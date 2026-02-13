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
    (void)args;
    (void)env;
    if (is_builtin(args[0])) {
        if (my_strcmp(args[0], "env") == 0) {
            print_env(env);
        }
    }
}
