/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_find_biggest_square
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(algo, find_biggest_square_basic)
{
    char l1[] = ".....";
    char l2[] = "..#..";
    char *map[] = { l1, l2, NULL };
    int row1[] = {1, 1, 1, 1, 1};
    int row2[] = {1, 1, 0, 1, 1};
    int *tab[] = { row1, row2, NULL };

    find_biggest_square(tab, map);
    cr_assert(1);
}

