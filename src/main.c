/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** main
*/

#include "../includes/my_radar.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        help();
        return 84;
    }
    if (my_strcmp(argv[1], "-h") || my_strcmp(argv[1], "--help")) {
        help();
        return 0;
    }
    return 0;
}
