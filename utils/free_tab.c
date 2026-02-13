/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** free_tab
*/

#include "my.h"

void strtab_free(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    for (i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
}

void free_tab_n(char **tab, int n)
{
    int i;

    if (!tab)
        return;
    for (i = 0; i < n; i++)
        free(tab[i]);
    free(tab);
}
