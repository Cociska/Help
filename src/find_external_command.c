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
    char *token = strtok(path_env, ":");
    char *full_path = NULL;
    char *temp = NULL;

    while (token != NULL) {
        temp = my_strmerge(token, "/");
        full_path = my_strmerge(temp, command);
        free(temp);
        if (access(full_path, X_OK) == 0) {
            free(path_env);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    free(path_env);
    return NULL;
}
