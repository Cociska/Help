/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
