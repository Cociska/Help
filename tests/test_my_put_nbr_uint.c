/*
** EPITECH PROJECT, 2025
** test_my_put_float.c
** File description:
** testing my_put_float.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_put_nbr_uint, basic)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%u", 0);
    my_put_nbr_uint(0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr_uint, large_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%ld", 4294967295);
    my_put_nbr_uint(4294967295);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr_uint, mid_range)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%u", 1234567890);
    my_put_nbr_uint(1234567890);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr_uint, single_digit)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%u", 7);
    my_put_nbr_uint(7);
    cr_assert_stdout_eq_str(expected);
}
