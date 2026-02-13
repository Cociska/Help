/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_strdup_tab.c
*/

#include "my.h"
#include "mini_shell.h"

char **my_strdup_tab(char **tab)
{
    int len;
    char **new_tab;
    int i;

    if (!tab)
        return NULL;
    len = strtab_len(tab);
    new_tab = malloc(sizeof(char *) * (len + 1));
    if (!new_tab)
        return NULL;
    for (i = 0; i < len; i++) {
        new_tab[i] = my_strdup(tab[i]);
        if (!new_tab[i]) {
            free_tab_n(new_tab, i);
            return NULL;
        }
    }
    new_tab[len] = NULL;
    return new_tab;
}
