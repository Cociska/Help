/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** my_putchar
*/

#include "../../include/setting_up.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
