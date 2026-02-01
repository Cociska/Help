/*
** EPITECH PROJECT, 2025
** my_str_isupper.c
** File description:
** is upper ?
*/

#include "../../include/my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[0] == '\0') {
        return 1;
    }
    for (; str[i]; i++) {
        if (!(str[i] < 65 || str[i] > 91)) {
            return 0;
        }
    }
    return 1;
}
