/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** map_gen
*/

#include "../../include/setting_up.h"

char **map_gen(int size, char *pattern)
{
    int plen = my_strlen(pattern);
    char **map = NULL;

    if (size <= 0 || plen <= 0)
        return NULL;
    map = malloc(sizeof(char *) * (size + 1));
    if (!map)
        return NULL;
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(char) * (size + 1));
        if (!map[i])
            return NULL;
        for (int j = 0; j < size; j++)
            map[i][j] = pattern[(i + j) % plen];
        map[i][size] = '\0';
    }
    map[size] = NULL;
    return map;
}
