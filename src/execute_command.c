/*
** EPITECH PROJECT, 2026
** G-PSU-200
** File description:
** execute_commande
*/

#include "my.h"
#include "mini_shell.h"

static int is_builtin(char *command)
{
    int i = 0;
    char *builtins[6];

    if (!command)
        return (0);
    builtins[0] = "cd";
    builtins[1] = "exit";
    builtins[2] = "env";
    builtins[3] = "setenv";
    builtins[4] = "unsetenv";
    builtins[5] = NULL;
    for (; builtins[i] != NULL; i++)
        if (my_strcmp(command, builtins[i]) == 0)
            return 1;
    return 0;
}

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
        my_putstr("Error");
    else if (pid == 0)
        execve(path, args, env);
    else
        waitpid(pid, &status, 0);
}

void execute_command(char **args, char **env)
{
    char *path = find_external_command(args[0], env);

    if (!args || !args[0])
        return;
    if (is_builtin(args[0]))
        execute_builtin(args, env);
    else if (path != NULL)
        execute_externe(args, env);
    else {
        my_putstr(args[0]);
        my_putstr(": Command not found.\n");
    }
}
