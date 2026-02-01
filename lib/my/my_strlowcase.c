/*
** EPITECH PROJECT, 2025
** my_strlowcase.c
** File description:
** lowercase
*/

#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] < 91 && str[i] > 64) {
            str[i] += 32;
        }
    }
    return str;
}
