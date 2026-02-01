/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** my_putchar
*/

#include "../../include/my.h"
#include <unistd.h>

int my_putchar(char c)
{
    int count = 1;

    write(1, &c, 1);
    return count;
}
