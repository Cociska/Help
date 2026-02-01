/*
** EPITECH PROJECT, 2025
** my_stupcase.c
** File description:
** uppercase
*/

#include "../../include/my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] < 123 && str[i] > 96) {
            str[i] -= 32;
        }
    }
    return str;
}
