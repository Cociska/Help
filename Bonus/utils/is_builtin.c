/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** is_builtin
*/

#include "my.h"
#include "mini_shell.h"

int is_builtin(char *command)
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
