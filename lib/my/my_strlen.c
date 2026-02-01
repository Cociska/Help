/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** len function
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return i;
}
