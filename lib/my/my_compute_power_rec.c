/*
** EPITECH PROJECT, 2025
** my_compute_power_rec.c
** File description:
** power
*/

#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    int base = nb;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    } else {
        nb *= my_compute_power_rec(base, p - 1);
        return nb;
    }
}
