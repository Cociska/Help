/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** print_prompt
*/

#include "mini_shell.h"

void print_prompt(void)
{
    char *cwd = getcwd(NULL, 0);

    if (cwd == NULL)
        return;
    my_putcolor(BLUE, cwd, 1);
    free(cwd);
    my_putstr(" >$ ");
}
