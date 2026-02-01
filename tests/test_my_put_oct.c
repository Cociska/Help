/*
** EPITECH PROJECT, 2025
** test_my_put_oct.c
** File description:
** testing my_put_oct.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_put_oct, integer)
{
    cr_redirect_stdout();
    my_put_oct(7);
    cr_assert_stdout_eq_str("7");
}

Test(my_put_oct, larger_integer)
{
    cr_redirect_stdout();
    my_put_oct(9);
    cr_assert_stdout_eq_str("11");
}

Test(my_put_oct, negative)
{
    cr_redirect_stdout();
    my_put_oct(-9);
    cr_assert_stdout_eq_str("37777777767");
}

Test(my_put_oct, zero)
{
    cr_redirect_stdout();
    my_put_oct(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_oct, larger_number)
{
    cr_redirect_stdout();
    my_put_oct(1234);
    cr_assert_stdout_eq_str("2322");
}

Test(my_put_oct, int_max)
{
    cr_redirect_stdout();
    my_put_oct(2147483647);
    cr_assert_stdout_eq_str("17777777777");
}
