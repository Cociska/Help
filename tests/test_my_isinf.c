/*
** EPITECH PROJECT, 2025
** test_my_isinf.c
** File description:
** testing my_isinf.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_isinf, inf)
{
    double x = 1.0 / 0.0;
    int res = 1;

    cr_assert_eq(my_isinf(x), res);
}

Test(my_isinf, not_inf)
{
    double x = 42.0;
    int res = 0;

    cr_assert_eq(my_isinf(x), res);
}
