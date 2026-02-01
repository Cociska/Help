/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** reversing str
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}
