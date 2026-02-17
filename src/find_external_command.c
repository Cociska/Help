/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** find_external_command
*/

#include "my.h"
#include "mini_shell.h"

char *find_external_command(char *command, char **env)
{
    char *path_env = get_env(env, "PATH");
    char *env_copy = my_strdup(path_env);
    char *token = strtok(env_copy, ":");
    char *full_path = NULL;
    char *temp = NULL;

    while (token != NULL) {
        temp = my_strmerge(token, "/");
        full_path = my_strmerge(temp, command);
        free(temp);
        if (access(full_path, X_OK) == 0) {
            free(env_copy);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    free(env_copy);
    return NULL;
}
