/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** builtin_unsetenv
*/

#include "my.h"
#include "mini_shell.h"

static void shift_env(char **env, int start)
{
    int j = start;

    for (; env[j] != NULL; j++)
        env[j] = env[j + 1];
}

int builtin_unsetenv(char ***env, char **args)
{
    char *var;

    if (handle_env_errors(args, env, 2))
        return -1;
    var = my_strmerge(args[1], "=");
    for (int i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], var, my_strlen(var)) == 0) {
            free((*env)[i]);
            shift_env(*env, i);
            break;
        }
    }
    free(var);
    return 0;
}
