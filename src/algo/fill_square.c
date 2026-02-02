/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** fill_square
*/

#include "../../include/setting_up.h"

void fill_square(char **map, int size, int ei, int ej)
{
    int i;
    int j;

    for (i = ei; i > ei - size; i--)
        for (j = ej; j > ej - size; j--)
            map[i][j] = 'x';
}
