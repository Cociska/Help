/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** read_file
*/

#include "../../include/setting_up.h"

static char *read_full(int fd)
{
    char *buffer = malloc(sizeof(char) * 10000);
    int size = 0;

    if (!buffer)
        return NULL;
    size = read(fd, buffer, 9999);
    if (size <= 0) {
        free(buffer);
        return NULL;
    }
    buffer[size] = '\0';
    return buffer;
}

char **read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;

    if (fd < 0)
        return NULL;
    buffer = read_full(fd);
    close(fd);
    if (!buffer)
        return NULL;
    return parse_lines(buffer);
}
