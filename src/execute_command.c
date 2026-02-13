/*
** EPITECH PROJECT, 2026
** G-PSU-200
** File description:
** execute_commande
*/

#include "my.h"
#include "mini_shell.h"

int is_builtin(char *command)
{
    char *builtins[] = {
        "cd",
        "exit",
        "env",
        "setenv",
        "unsetenv",
        NULL
    };
    int i = 0;

    for (; builtins[i] != NULL; i++) {
        if (my_strcmp(command, builtins[i]) == 0)
            return 1;
    }
    return 0;
}

void execute_command(char **args, char **env)
{
    if (!args || !args[0])
        return;
    if (is_builtin(args[0])) {
        if (my_strcmp(args[0], "cd") == 0) {
            builtin_cd(env, args);
        }
        if (my_strcmp(args[0], "env") == 0) {
            buildin_env(env);
        }
    }
}
