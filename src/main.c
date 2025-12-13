/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** main entry point
*/

#include "../includes/my_radar.h"

int main(int argc, char **argv)
{
    game_t game;

    if (argc == 2 && (my_strcmp(argv[1], "-h") == 0 ||
            my_strcmp(argv[1], "--help") == 0)) {
        help();
        return 0;
    }
    if (argc != 2) {
        write(2, "./my_radar: bad arguments, try -h\n", 34);
        return 84;
    }
    return open_window(&game);
}
