/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** auth
*/

#include "../include/my_sudo.h"
#include <crypt.h>

static int read_input(char *in, size_t size, const char *user)
{
    char prompt[512];

    snprintf(prompt, sizeof(prompt), "[my_sudo] password for %s: ", user);
    write(2, prompt, strlen(prompt));
    if (!fgets(in, size, stdin))
        return 84;
    in[strcspn(in, "\n")] = '\0';
    return 0;
}

int read_hash(const char *u, char *out, size_t s)
{
    FILE *f = fopen("/etc/shadow", "r");
    char buf[4096];
    char *name;
    char *hash;

    if (!f)
        return -1;
    while (fgets(buf, sizeof(buf), f)) {
        name = strtok(buf, ":");
        hash = strtok(NULL, ":");
        if (name && hash && !strcmp(name, u)) {
            strncpy(out, hash, s - 1);
            out[s - 1] = 0;
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return -1;
}

int auth_user(const char *u)
{
    char h[4096];
    char in[256];
    int tries = 0;
    char *c;

    if (read_hash(u, h, sizeof(h)) < 0)
        return 84;
    while (tries < 3) {
        if (read_input(in, sizeof(in), u) != 0)
            return 84;
        c = crypt(in, h);
        if (c && !strcmp(c, h))
            return 0;
        write(2, "Sorry, try again.\n", 18);
        tries++;
    }
    return 84;
}
