/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** test_my_putchar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"
#include <stdio.h>

Test(utils, my_putchar_basic)
{
    cr_redirect_stdout();
    my_putchar('A');
    fflush(stdout);
    cr_assert_stdout_eq_str("A");
}
