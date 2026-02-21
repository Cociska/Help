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

static void remove_var(char ***env, char *var)
{
    int i;
    int len = my_strlen(var);

    for (i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], var, len) == 0) {
            free((*env)[i]);
            shift_env(*env, i);
            return;
        }
    }
}

int builtin_unsetenv(char ***env, char **args)
{
    char *var;
    int k;

    if (handle_env_errors(args, env, 2))
        return 1;
    for (k = 1; args[k] != NULL; k++) {
        var = my_strmerge(args[k], "=");
        remove_var(env, var);
        free(var);
    }
    return 0;
}
