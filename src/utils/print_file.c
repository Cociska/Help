/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** print_file
*/

#include "../../include/setting_up.h"

void print_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char c;

    if (fd < 0)
        return;
    while (read(fd, &c, 1) > 0)
        my_putchar(c);
    close(fd);
}
