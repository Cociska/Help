/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** policy
*/

#include "../include/my_sudo.h"
#include <stdlib.h>

static char *skip_spaces(char *s)
{
    while (*s == ' ' || *s == '\t')
        s++;
    return s;
}

static int is_comment_line(const char *s)
{
    if (*s != '#')
        return 0;
    if (*(s + 1) >= '0' && *(s + 1) <= '9')
        return 0;
    return 1;
}

static int match_numeric_user(const char *token, uid_t uid)
{
    if (token[0] != '#')
        return 0;
    return (uid_t)strtoul(token + 1, NULL, 10) == uid;
}

static int match_group_gid(const char *token, const char *user, gid_t gid)
{
    gid_t token_gid = 0;

    if (strncmp(token, "%#", 2) != 0)
        return 0;
    token_gid = (gid_t)strtoul(token + 2, NULL, 10);
    if (token_gid == gid)
        return 1;
    return is_user_in_group_gid(user, token_gid);
}

static int match_group_name(const char *token, const char *user)
{
    if (token[0] != '%' || token[1] == '#')
        return 0;
    return is_user_in_group_name(user, token + 1);
}

static int line_matches(char *line, const char *user, uid_t uid, gid_t gid)
{
    char *token = NULL;

    line = skip_spaces(line);
    if (*line == '\0' || *line == '\n' || is_comment_line(line))
        return 0;
    token = strtok(line, " \t\n");
    if (!token)
        return 0;
    if (strcmp(token, user) == 0)
        return 1;
    if (match_numeric_user(token, uid))
        return 1;
    if (match_group_name(token, user))
        return 1;
    if (match_group_gid(token, user, gid))
        return 1;
    return 0;
}

int is_user_allowed(const char *user, uid_t uid, gid_t gid)
{
    FILE *f = fopen("/etc/sudoers", "r");
    char line[4096];

    if (!f)
        return 84;
    while (fgets(line, sizeof(line), f))
        if (line_matches(line, user, uid, gid)) {
            fclose(f);
            return 0;
        }
    fclose(f);
    return 1;
}
