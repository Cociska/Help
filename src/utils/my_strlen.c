/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** my_strlen
*/

#include "../../include/setting_up.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
