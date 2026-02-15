/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** builtin_setenv
*/

#include "my.h"
#include "mini_shell.h"

/*

int builtin_setenv(char ***env, char **args)
{
    if (!args[1]) {
        my_putstr("setenv: Too few arguments\n");
        return 1;
    }
    if (args[2]) {
        my_putstr("setenv: Too many arguments\n");
        return 1;
    }
    if (my_strlen_tab(*env) == 0) {
        *env = malloc(sizeof(char *) * 2);
        (*env)[0] = my_strmerge(args[1], "=");
        (*env)[1] = NULL;
        return 0;
    }
    for (int i = 0; (*env)[i]; i++) {
        if (my_strncmp((*env)[i], args[1], my_strlen(args[1])) == 0) {
            free((*env)[i]);
            (*env)[i] = my_strmerge(args[1], "=");
            return 0;
        }
    }
    int len = my_strlen_tab(*env);
    *env = realloc(*env, sizeof(char *) * (len + 2));
    (*env)[len] = my_strmerge(args[1], "=");
    (*env)[len + 1] = NULL;
    return 0;
}

*/
