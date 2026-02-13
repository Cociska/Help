/*
** EPITECH PROJECT, 2026
** G-PSU-200
** File description:
** print_env
*/

#include "my.h"

void print_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++){
        my_putstr(env[i]);
        my_putchar('\n');
    }
}
