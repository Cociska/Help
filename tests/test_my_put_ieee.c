/*
** EPITECH PROJECT, 2025
** test_my_put_ieee.c
** File description:
** testing my_put_ieee.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"
#include <stdio.h>

Test(my_put_ieee, integer)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%a", 5.0);
    my_put_ieee(5.0, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_ieee, not_a_number)
{
    char expected[20];
    double nan = 0.0 / 0.0;

    cr_redirect_stdout();
    sprintf(expected, "%a", nan);
    my_put_ieee(nan, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_ieee, not_a_number_cap)
{
    char expected[20];
    double nan = 0.0 / 0.0;

    cr_redirect_stdout();
    sprintf(expected, "%A", nan);
    my_put_ieee(nan, 1);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_ieee, decimal)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%A", 3.14);
    my_put_ieee(3.14, 1);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_ieee, negative)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%a", -2.5);
    my_put_ieee(-2.5, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_ieee, zero)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%a", 0.0);
    my_put_ieee(0.0, 0);
    cr_assert_stdout_eq_str(expected);
}
