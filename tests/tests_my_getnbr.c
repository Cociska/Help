/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_my_getnbr
*/

#include <criterion/criterion.h>
#include "../include/setting_up.h"

Test(utils, my_getnbr_simple)
{
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr("42"), 42);
    cr_assert_eq(my_getnbr("999"), 999);
}

Test(utils, my_getnbr_negative)
{
    cr_assert_eq(my_getnbr("-1"), -1);
    cr_assert_eq(my_getnbr("-123"), -123);
}
