/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** my_putstr
*/

#include "../../include/setting_up.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
