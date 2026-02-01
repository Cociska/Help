/*
** EPITECH PROJECT, 2025
** test_my_put_nbr.c
** File description:
** testing my_put_nbr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(my_put_nbr, dnegative)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%d", -5);
    my_put_nbr(-5);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, dzero)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%d", 0);
    my_put_nbr(0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, dnumber)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%d", 67);
    my_put_nbr(67);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, dlarger_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%d", 123456);
    my_put_nbr(123456);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, inegative)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%i", -456);
    my_put_nbr(-456);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, izero)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%i", 0);
    my_put_nbr(0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, inumber)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%i", 45);
    my_put_nbr(45);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_nbr, ilarger_number)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%i", 56789);
    my_put_nbr(56789);
    cr_assert_stdout_eq_str(expected);
}
