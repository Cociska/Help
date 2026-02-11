/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** print_env
*/

#include "mini_shell.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}
