/*
** EPITECH PROJECT, 2025
** my_strcapitalize.c
** File description:
** capitals
*/

#include "../../include/my.h"

static int condition(char c)
{
    return ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'));
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'
            && (i == 0 || !condition(str[i - 1])))
            str[i] -= 32;
    }
    return str;
}
