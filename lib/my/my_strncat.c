/*
** EPITECH PROJECT, 2025
** my_strncat.c
** File description:
** idk
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0' && j != nb; j++) {
        dest[i + j] = src[j];
        dest[i + j + 1] = '\0';
    }
    return dest;
}
