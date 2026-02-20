/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** remove_path_start
*/

#include "mini_shell.h"
#include "my.h"

char *remove_path_start(char *path)
{
    char *new_path;
    char *home = "/home/cociska";
    int len_home = my_strlen(home);

    if (!path)
        return NULL;
    if (!my_strncmp(home, path, len_home)) {
        new_path = my_strmerge("~", path + len_home);
        return new_path;
    }
    return path;
}
