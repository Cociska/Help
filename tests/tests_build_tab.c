/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_build_tab
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(algo, build_tab_basic)
{
    char *lines[] = {".....", ".##..", NULL};
    int **tab = build_tab(lines);

    cr_assert_not_null(tab);
}
