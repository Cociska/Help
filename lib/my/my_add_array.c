/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_tab_push_back
*/

#include "my.h"
#include "mini_shell.h"

static void free_partial(char **tab, int up_to)
{
    for (int i = 0; i < up_to; i++)
        free(tab[i]);
    free(tab);
}

static char **copy_tab_elements(char **tab, char **new_tab, int len)
{
    for (int i = 0; i < len; i++) {
        new_tab[i] = my_strdup(tab[i]);
        if (new_tab[i] == NULL) {
            free_partial(new_tab, i);
            return NULL;
        }
    }
    return new_tab;
}

char **my_add_array(char **tab, char *elem)
{
    int len = 0;
    char **new_tab = NULL;

    if (elem == NULL)
        return tab;
    if (tab != NULL)
        len = my_strlen_tab(tab);
    new_tab = malloc(sizeof(char *) * (len + 2));
    if (new_tab == NULL)
        return NULL;
    if (copy_tab_elements(tab, new_tab, len) == NULL)
        return NULL;
    new_tab[len] = my_strdup(elem);
    if (new_tab[len] == NULL) {
        free_partial(new_tab, len);
        return NULL;
    }
    new_tab[len + 1] = NULL;
    strtab_free(tab);
    return new_tab;
}
