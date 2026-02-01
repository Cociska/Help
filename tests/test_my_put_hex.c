/*
** EPITECH PROJECT, 2025
** test_my_put_hex.c
** File description:
** testing my_put_hex.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_put_hex, integer)
{
    cr_redirect_stdout();
    my_put_hex(12, 0);
    cr_assert_stdout_eq_str("c");
}

Test(my_put_hex, larger_integer)
{
    cr_redirect_stdout();
    my_put_hex(999, 0);
    cr_assert_stdout_eq_str("3e7");
}

Test(my_put_hex, negative)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%x", (unsigned int)(-12));
    my_put_hex(-12, 0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_hex, zero)
{
    cr_redirect_stdout();
    my_put_hex(0, 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_hex, cap)
{
    cr_redirect_stdout();
    my_put_hex(127, 1);
    cr_assert_stdout_eq_str("7F");
}
