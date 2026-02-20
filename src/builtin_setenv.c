/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** builtin_setenv
*/

#include "my.h"
#include "mini_shell.h"

static char **my_add_env(char **env, char *new_var, char *var_name)
{
    int i;
    int var_len = my_strlen(var_name);

    for (i = 0; env[i] != NULL; i++){
        if (my_strncmp(env[i], var_name, var_len) == 0 &&
            env[i][var_len] == '=') {
            free(env[i]);
            env[i] = my_strdup(new_var);
            return env;
        }
    }
    env[i] = my_strdup(new_var);
    env[i + 1] = NULL;
    return env;
}

int builtin_setenv(char ***env, char **args)
{
    char *new_var;
    char *temp;

    if (handle_env_errors(args, env, 1))
        return -1;
    temp = my_strmerge(args[1], "=");
    new_var = my_strmerge(temp, args[2] ? args[2] : "");
    free(temp);
    *env = my_add_env(*env, new_var, args[1]);
    free(new_var);
    if (*env == NULL)
        return -1;
    return 0;
}
