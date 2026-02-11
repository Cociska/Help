/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** colors
*/

#ifndef MINI_SHELL_1_COLORS_H
    #define MINI_SHELL_1_COLORS_H

    #define GREEN "\033[32m"
    #define BLUE "\033[34m"
    #define RESET "\033[0m"
    #define BOLD "\033[1m"
    #define GREEN_LEN 5
    #define BLUE_LEN 5
    #define RESET_LEN 4

void my_putcolor(const char *color, const char *text, int bold);

#endif //MINI_SHELL_1_COLORS_H
