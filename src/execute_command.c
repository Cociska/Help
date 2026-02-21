/*
** EPITECH PROJECT, 2026
** G-PSU-200
** File description:
** execute_commande
*/

#include "my.h"
#include "mini_shell.h"

static int execute_builtin(char **args, char ***env)
{
    if (my_strcmp(args[0], "cd") == 0)
        return builtin_cd(env, args);
    if (my_strcmp(args[0], "env") == 0)
        return buildin_env(*env, args);
    if (my_strcmp(args[0], "setenv") == 0)
        return builtin_setenv(env, args);
    if (my_strcmp(args[0], "unsetenv") == 0)
        return builtin_unsetenv(env, args);
    return 0;
}

int execute_externe(char **args, char **env, char *path)
{
    pid_t pid = fork();
    int status;

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        execve(path, args, env);
        perror("execve");
        exit(126);
    }
    waitpid(pid, &status, 0);
    handle_errors(status);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status))
        return WTERMSIG(status) + 128;
    return 0;
}

int execute_command(char **args, char ***env, char *line, int status)
{
    char *path;

    if (!args || !args[0])
        return status;
    if (my_strcmp(args[0], "exit") == 0) {
        free(line);
        strtab_free(args);
        strtab_free(*env);
        exit(status);
    }
    if (is_builtin(args[0]))
        return execute_builtin(args, env);
    path = find_external_command(args[0], *env);
    if (path != NULL) {
        status = execute_externe(args, *env, path);
        free(path);
        return status;
    }
    my_put_error(my_strcat(args[0], ": Command not found.\n"));
    return 1;
}
