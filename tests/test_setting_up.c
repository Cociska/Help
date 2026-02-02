/*
** EPITECH PROJECT, 2025
** bsq_full
** File description:
** test_bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(setting_up, parse_lines_simple) {
    char buffer[] = "...\n..o\n";
    char **map = parse_lines(buffer);

    cr_assert_str_eq(map[0], "...");
    cr_assert_str_eq(map[1], "..o");
    cr_assert_null(map[2]);
}
