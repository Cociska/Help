/*
** EPITECH PROJECT, 2026
** Mini-shell
** File description:
** remove_newline
*/

#include "my.h"

char *remove_newline(char *str)
{
    int len;

    if (str == NULL)
        return NULL;
    len = my_strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
    return str;
}
