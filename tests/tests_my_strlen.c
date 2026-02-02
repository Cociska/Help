/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** test_my_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(utils, my_strlen_basic)
{
    cr_assert_eq(my_strlen("Hello"), 5);
    cr_assert_eq(my_strlen(""), 0);
}
