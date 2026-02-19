/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_putcolors
*/

#include "my.h"
#include "colors.h"

void my_putcolor(const char *color, const char *text, int bold)
{
    if (bold) {
        my_putstr("\033[1m");
    }
    my_putstr(color);
    my_putstr(text);
    my_putstr(RESET);
}
