/*
** EPITECH PROJECT, 2025
** my_strstr.c
** File description:
** find str
*/

#include "../../include/my.h"

static int compare(char *str, const char *to_find, int i)
{
    int x = 0;

    while (to_find[x] != '\0') {
        if (to_find[x] != str[i + x])
            return 0;
        x++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i]; i++) {
        if (compare(str, to_find, i))
            return &str[i];
    }
    return 0;
}
