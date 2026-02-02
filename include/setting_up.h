/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** setting_up
*/

#ifndef SETTING_UP_H
    #define SETTING_UP_H

    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct sq_s {
    int max;
    int ei;
    int ej;
} sq_t;

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
void print_file(char *filepath);
char **read_file(char *filepath);
char **parse_lines(char *buffer);
int **build_tab(char **map);
void find_biggest_square(int **tab, char **map);
void fill_square(char **map, int size, int ei, int ej);
char **map_gen(int size, char *pattern);
int my_getnbr(char *str);

#endif
