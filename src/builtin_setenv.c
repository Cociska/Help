/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** builtin_setenv
*/

#include "my.h"
#include "mini_shell.h"

void free_env(char **env, char *var_name, char *new_var)
{
    int i;
    int var_len = my_strlen(var_name);

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], var_name, var_len) == 0 &&
            env[i][var_len] == '=') {
            free(env[i]);
            env[i] = my_strdup(new_var);
            return;
        }
    }
}

char **my_add_env(char **env, char *new_var, char *var_name)
{
    int i;
    int len;
    char **new_env;

    free_env(env, var_name, new_var);
    for (len = 0; env[len] != NULL; len++);
    new_env = malloc(sizeof(char *) * (len + 2));
    if (!new_env)
        return NULL;
    for (i = 0; i < len; i++) {
        new_env[i] = env[i];
    }
    new_env[len] = my_strdup(new_var);
    new_env[len + 1] = NULL;
    free(env);
    return new_env;
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
