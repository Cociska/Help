/*
** EPITECH PROJECT, 2026
** G-PSU-200
** File description:
** execute_commande
*/

#include "my.h"
#include "mini_shell.h"

static void execute_builtin(char **args, char **env)
{
    if (my_strcmp(args[0], "cd") == 0)
        builtin_cd(env, args);
    if (my_strcmp(args[0], "exit") == 0)
        exit(0);
    if (my_strcmp(args[0], "env") == 0)
        buildin_env(env);
    if (my_strcmp(args[0], "setenv") == 0)
        builtin_setenv(&env, args);
    if (my_strcmp(args[0], "unsetenv") == 0)
        builtin_unsetenv(&env, args);
}

void execute_externe(char **args, char **env)
{
    char *path = find_external_command(args[0], env);
    pid_t pid = fork();
    int status;

    if (pid < 0)
        perror("fork");
    else if (pid == 0) {
        execve(path, args, env);
        perror("execve");
        exit(126);
    } else {
        waitpid(pid, &status, 0);
        handle_errors(status);
    }
}

void execute_command(char **args, char **env)
{
    char *path;

    if (!args || !args[0])
        return;
    path = find_external_command(args[0], env);
    if (is_builtin(args[0]))
        execute_builtin(args, env);
    else if (path != NULL)
        execute_externe(args, env);
    else {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n");
    }
}
