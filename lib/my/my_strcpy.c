/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** Copying
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(dest);

    for (int i = 0; i < len - 1; i++) {
        dest[i] = src[i];
    }
    return dest;
}
