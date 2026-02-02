/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_map_gen
*/

#include <criterion/criterion.h>
#include "../include/setting_up.h"

Test(gen, map_gen_basic)
{
    char **map = map_gen(3, "..o..");

    cr_assert_str_eq(map[0], "..o");
    cr_assert_str_eq(map[1], ".o.");
    cr_assert_str_eq(map[2], "o..");
    cr_assert_null(map[3]);
}

Test(gen, map_gen_invalid_size)
{
    cr_assert_null(map_gen(0, "..o.."));
    cr_assert_null(map_gen(-5, "..o.."));
}
