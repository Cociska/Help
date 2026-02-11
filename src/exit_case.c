/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** exit_case
*/

#include "mini_shell.h"

int exit_case(ssize_t status, char *line)
{
    if (status == -1) {
        my_putstr("\n");
        return 1;
    }
    if (is_exit(line))
        return 1;
    return 0;
}
