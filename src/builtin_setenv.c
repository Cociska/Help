/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** builtin_setenv
*/

#include "my.h"
#include "mini_shell.h"

int builtin_setenv(char ***env, char **args)
{
    char *new_var = malloc(sizeof(char) * (my_strlen(args[1]) + 2));

    if (!args[1]) {
        my_putstr("setenv: Too few arguments\n");
        return 1;
    }
    if (args[3]) {
        my_putstr("setenv: Too many arguments\n");
        return 1;
    }
    new_var = my_strmerge(args[1], "=");
    *env = my_add_array(*env, new_var);
    free(new_var);
    if (*env == NULL)
        return 1;
    return 0;
}
