/*
** EPITECH PROJECT, 2025
** my_str_isprintable.c
** File description:
** visible char ?
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[0] == '\0') {
        return 1;
    }
    for (; str[i]; i++) {
        if (!(str[i] > 32 && str[i] < 127)) {
            return 0;
        }
    }
    return 1;
}
