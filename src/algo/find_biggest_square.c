/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** find_biggest_square
*/

#include "../../include/setting_up.h"

static void condition(sq_t *s, int val, int i, int j)
{
    if (val > s->max) {
        s->max = val;
        s->ei = i;
        s->ej = j;
    }
}

void find_biggest_square(int **tab, char **map)
{
    int i = 0;
    int j = 0;
    sq_t s = {0, 0, 0};

    while (map[i] && tab[i]) {
        j = 0;
        while (map[i][j] && j >= 0) {
            condition(&s, tab[i][j], i, j);
            j++;
        }
        i++;
    }
    fill_square(map, s.max, s.ei, s.ej);
}
