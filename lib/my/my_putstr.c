/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** display all caracters
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    int count = 0;

    for (; str[i] != '\0'; i++){
        count += my_putchar(str[i]);
    }
    return count;
}
