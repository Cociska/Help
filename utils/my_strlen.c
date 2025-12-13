/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** my_strlen
*/

#include "../includes/my_radar.h"

int my_strlen(const char *s)
{
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }
    return len;
}
