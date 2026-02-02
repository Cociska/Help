/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** build_tab
*/

#include "../../include/setting_up.h"

int **new(int **tab, int i, int j)
{
    int a = tab[i - 1][j];
    int b = tab[i][j - 1];
    int c = tab[i - 1][j - 1];
    int min = a;

    if (tab[i][j] != 0) {
        if (b < min)
            min = b;
        if (c < min)
            min = c;
        tab[i][j] = min + 1;
    }
    return tab;
}

int **build_tab(char **map)
{
    int rows = 0;
    int i = 0;
    int j = 0;
    int cols = my_strlen(map[0]);
    int **tab;

    while (map[rows])
        rows++;
    tab = malloc(sizeof(int *) * rows);
    for (i = 0; i < rows; i++) {
        tab[i] = malloc(sizeof(int) * cols);
        if (!tab[i])
            return NULL;
        for (j = 0; j < cols; j++)
            tab[i][j] = (map[i][j] == 'o') ? 0 : 1;
    }
    for (i = 1; i < rows; i++)
        for (j = 1; j < cols; j++)
            new(tab, i, j);
    return tab;
}
