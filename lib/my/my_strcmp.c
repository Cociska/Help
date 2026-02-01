/*
** EPITECH PROJECT, 2025
** my_strcmp.c
** File description:
** compare two strings
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i]; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
    }
    if (s1[i] == '\0' && s2[i] != '\0') {
        return -1;
    }
    return 0;
}
