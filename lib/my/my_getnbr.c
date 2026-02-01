/*
** EPITECH PROJECT, 2025
** my_getnbr.c
** File description:
** get number
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int nb = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb * sign);
}
