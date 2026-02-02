/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_my_putstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"
#include <stdio.h>

Test(utils, my_putstr_basic)
{
    cr_redirect_stdout();
    my_putstr("ABC");
    fflush(stdout);
    cr_assert_stdout_eq_str("ABC");
}
