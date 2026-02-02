/*
** EPITECH PROJECT, 2025
** my_sudo_80
** File description:
** help
*/

#include "../include/my_sudo.h"

void print_help(int fd)
{
    const char *help_message =
        "usage: ./my_sudo -h\n"
        "usage: ./my_sudo [-ug] [command [args ...]]\n";

    write(fd, help_message, strlen(help_message));
}
