/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** my_getenv
*/

#include "my.h"

char *my_getenv(char **env, char *name)
{
    int len;

    if (!env || !name)
        return NULL;
    len = my_strlen(name);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
            return env[i] + len + 1;
    }
    return NULL;
}
