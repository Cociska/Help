/*
** EPITECH PROJECT, 2025
** my_put_nbr.c
** File description:
** test
*/

#include "../../include/my.h"

static void display_num(int nb, int *count)
{
    int x = 0;
    int temp = 0;

    while (nb != 0) {
        temp *= 10;
        x = nb % 10;
        temp += x;
        nb /= 10;
    }
    while (temp != 0) {
        x = temp % 10;
        temp /= 10;
        *count += my_putchar(x + 48);
    }
}

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = -nb;
        count += my_putchar(45);
        display_num(nb, &count);
    } else if (nb == 0) {
        count += my_putchar(48);
        return count;
    } else {
        display_num(nb, &count);
    }
    return count;
}
