/*
** EPITECH PROJECT, 2025
** my_str_isnum.c
** File description:
** is num ?
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '\0') {
        return 1;
    }
    for (; str[i]; i++){
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}
