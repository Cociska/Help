/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** copying n caracters
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
