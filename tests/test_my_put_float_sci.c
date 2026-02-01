/*
** EPITECH PROJECT, 2025
** test_my_put_float.c
** File description:
** testing my_put_float.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_put_float_sci, positive_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", 9.87654321);
    my_put_float_sci(9.87654321, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, negative_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", -9.87654321);
    my_put_float_sci(-9.87654321, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, zero)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", 0.0);
    my_put_float_sci(0.0, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, zero_neg)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", -0.0);
    my_put_float_sci(-0.0, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, large_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", 123456789.0);
    my_put_float_sci(123456789.0, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, small_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", 0.000123456);
    my_put_float_sci(0.000123456, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, rounding)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", 9.9999999);
    my_put_float_sci(9.9999999, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_float_sci, negative_exponent)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%e", 0.00000987654);
    my_put_float_sci(0.00000987654, 0);
    cr_assert_stdout_eq_str(expected);
}
