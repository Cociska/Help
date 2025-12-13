/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** helper
*/

#include "../includes/my_radar.h"

void help(void)
{
    char *message =
        "Air traffic simulation panel\n"
        "USAGE\n"
        "  ./my_radar [OPTIONS] path_to_script\n"
        "    path_to_script    The path to thr script file.\n"
        "OPTIONS\n"
        "  -h                print the usage and quit.\n"
        "USER INTERACTIONS\n"
        "  'L' key        enable/disable hitboxes and areas.\n"
        "  'S' key        enable/disable sprites.\n";

    write(1, message, my_strlen(message));
}
