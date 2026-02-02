/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_parse_lines
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(file, parse_lines_basic)
{
    char buffer[] = "line1\nline2\n";
    char **res = parse_lines(buffer);

    cr_assert_not_null(res);
}
