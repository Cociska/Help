/*
** EPITECH PROJECT, 2025
** my_compute_square_root.c
** File description:
** square root
*/

#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    for (int i = 1; i * i < nb + 1; i++) {
        if (nb == 1) {
            return 1;
        }
        if ((i * i) == nb) {
            return i;
        }
    }
    return 0;
}
