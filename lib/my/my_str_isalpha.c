/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** is caracters
*/

#include "../../include/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0'){
        return 1;
    }
    for (; str[i]; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') ||
            !(str[i] >= 'A' && str[i] <= 'Z')) {
            return 0;
        }
    }
    return 1;
}
