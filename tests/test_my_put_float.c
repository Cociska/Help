/*
** EPITECH PROJECT, 2025
** test_my_put_float.c
** File description:
** testing my_put_float.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_put_float, integer)
{
    cr_redirect_stdout();
    my_put_float(5, 2, 0);
    cr_assert_stdout_eq_str("5.00");
}

Test(my_put_float, not_a_number)
{
    double nan = 0.0 / 0.0;

    cr_redirect_stdout();
    my_put_float(nan, 6, 0);
    cr_assert_stdout_eq_str("nan");
}

Test(my_put_float, not_a_number_cap)
{
    double nan = 0.0 / 0.0;

    cr_redirect_stdout();
    my_put_float(nan, 6, 1);
    cr_assert_stdout_eq_str("NAN");
}

Test(my_put_float, decimal)
{
    cr_redirect_stdout();
    my_put_float(3.14, 2, 0);
    cr_assert_stdout_eq_str("3.14");
}

Test(my_put_float, precision)
{
    cr_redirect_stdout();
    my_put_float(1.234567, 6, 0);
    cr_assert_stdout_eq_str("1.234567");
}

Test(my_put_float, negative)
{
    cr_redirect_stdout();
    my_put_float(-2.5, 3, 0);
    cr_assert_stdout_eq_str("-2.500");
}

Test(my_put_float, zero)
{
    cr_redirect_stdout();
    my_put_float(0.0, 5, 0);
    cr_assert_stdout_eq_str("0.00000");
}

Test(my_put_float, large_precision)
{
    cr_redirect_stdout();
    my_put_float(1.0 / 3.0, 10, 0);
    cr_assert_stdout_eq_str("0.3333333333");
}
