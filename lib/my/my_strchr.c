/*
** EPITECH PROJECT, 2026
** my_strchr
** File description:
** Locates character in string
*/

#include "my.h"

char *my_strchr(const char *s, int c)
{
    int i = 0;

    for (; s[i]; i++) {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
    }
    if ((char)c == '\0')
        return ((char *)s);
    return NULL;
}
