/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** main
*/

#include "../include/setting_up.h"

static int solve_and_print(char **map)
{
    int **tab = NULL;
    int i = 0;

    if (!map)
        return 84;
    tab = build_tab(map);
    if (!tab)
        return 84;
    find_biggest_square(tab, map);
    for (i = 0; map[i]; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return 0;
}

int main(int ac, char **av)
{
    char **map = NULL;
    int size = 0;

    if (ac == 2) {
        map = read_file(av[1]);
        if (!map)
            return 84;
        return solve_and_print(map);
    }
    if (ac == 3) {
        size = my_getnbr(av[1]);
        if (size <= 0)
            return 84;
        map = map_gen(size, av[2]);
        return solve_and_print(map);
    }
    my_putstr("Usage:\n");
    my_putstr("./setting_up <map_file>\n");
    my_putstr("./setting_up <size> <pattern>\n");
    return 84;
}
