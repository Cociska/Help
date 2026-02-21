/*
** EPITECH PROJECT, 2026
** G-PSU-200
** File description:
** print_env
*/

#include "my.h"

int buildin_env(char **env, char **args)
{
    int i;

    if (args && args[1] != NULL) {
        my_put_error("env: ‘");
        my_put_error(args[1]);
        my_put_error("’: No such file or directory\n");
        return 127;
    }
    for (i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return 0;
}
