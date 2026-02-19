/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** builtin_unsetenv
*/

#include "my.h"
#include "mini_shell.h"

int builtin_unsetenv(char ***env, char **args)
{
    char *var;

    if (handle_env_errors(args, env, 2))
        return -1;
    var = my_strmerge(args[1], "=");
    for (int i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], var, my_strlen(var)) == 0) {
            free((*env)[i]);
            (*env)[i] = (*env)[i + 1];
            break;
        }
    }
    free(var);
    return 0;
}
