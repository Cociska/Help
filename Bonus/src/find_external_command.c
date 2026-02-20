/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** find_external_command
*/

#include "my.h"
#include "mini_shell.h"

char *check_absolute_path(char *command)
{
    if (command[0] == '/' || command[0] == '.') {
        if (access(command, X_OK) == 0)
            return my_strdup(command);
        return NULL;
    }
    return NULL;
}

char *search_in_path(char *command, char *env_copy)
{
    char *token = strtok(env_copy, ":");
    char *full_path = NULL;
    char *temp = NULL;

    while (token != NULL) {
        temp = my_strmerge(token, "/");
        full_path = my_strmerge(temp, command);
        free(temp);
        if (access(full_path, X_OK) == 0)
            return full_path;
        free(full_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}

char *find_external_command(char *command, char **env)
{
    char *path_env = my_getenv(env, "PATH");
    char *env_copy = my_strdup(path_env);
    char *result = check_absolute_path(command);

    if (result != NULL) {
        free(env_copy);
        return result;
    }
    result = search_in_path(command, env_copy);
    free(env_copy);
    return result;
}
