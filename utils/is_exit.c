/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** is_exit
*/

#include "mini_shell.h"

int is_exit(char *line)
{
    if (my_strcmp(line, "exit\n") == 0 || my_strcmp(line, "exit") == 0)
        return 1;
    return 0;
}
