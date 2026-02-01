/*
** EPITECH PROJECT, 2025
** my_find_prime_sup.c
** File description:
** prime
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 1) {
        return 2;
    }
    if (my_is_prime(nb) == 1) {
        return nb;
    }
    while (my_is_prime(nb) == 0) {
        nb++;
    }
    return nb;
}
