/*
** EPITECH PROJECT, 2025
** my_isneg.c
** File description:
** A fonction that display if the integer,
** passer as parameter is negative or positive.
*/

#include <unistd.h>
#include "../../include/my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    my_putchar('\n');
    return 0;
}
