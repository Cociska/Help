/*
** EPITECH PROJECT, 2025
** test_my_putstr.c
** File description:
** testing my_putstr.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(my_putstr, negative)
{
    cr_redirect_stdout();
    my_putstr("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(my_putstr, empty)
{
    cr_redirect_stdout();
    my_putstr("");
    cr_assert_stdout_eq_str("");
}
