/*
** EPITECH PROJECT, 2025
** my_str_islower.c
** File description:
** is lowr ?
*/

#include "../../include/my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[0] == '\n') {
        return 1;
    }
    for (; str[i]; i++) {
        if (!(str[i] < 97 || str[i] > 122)) {
            return 0;
        }
    }
    return 1;
}
