/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** get_env
*/

#include "my.h"

char *get_env(char **env, char *name)
{
    int len;

    if (!env || !name)
        return NULL;
    len = my_strlen(name);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, len) == 0
            && env[i][len] == '=')
            return env[i] + len + 1;
    }
    return NULL;
}
