/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_put_nbr_error
*/

#include "my.h"

void my_put_nbr_error(int nb)
{
    char buffer[12];

    if (nb == -2147483648) {
        my_put_error("-2147483648");
        return;
    }
    if (nb < 0) {
        my_put_error("-");
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr_error(nb / 10);
    buffer[0] = (nb % 10) + '0';
    buffer[1] = '\0';
    write(2, &buffer, 1);
}
