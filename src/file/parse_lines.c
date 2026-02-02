/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** parse_lines
*/

#include "../../include/setting_up.h"

int lines_count(char *buffer)
{
    int i = 0;
    int lines = 1;

    while (buffer[i]) {
        if (buffer[i] == '\n')
            lines++;
        i++;
    }
    return lines;
}

char **parse_lines(char *buffer)
{
    int i = 0;
    int idx = 0;
    int lines = lines_count(buffer);
    char *start = buffer;
    char **arr = malloc(sizeof(char *) * (lines + 1));

    if (!arr)
        return NULL;
    while (buffer[i]) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            arr[idx] = start;
            idx++;
            start = buffer + i + 1;
        }
        i++;
    }
    arr[idx] = NULL;
    return arr;
}
