/*
** EPITECH PROJECT, 2025
** test_my_put_pointer.c
** File description:
** testing my_put_pointer.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_put_pointer, zero)
{
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%p", (void *)0);
    my_put_pointer(0);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_pointer, non_null)
{
    int x = 0;
    int *ptr = &x;
    char expected[20];

    cr_redirect_stdout();
    sprintf(expected, "%p", (void *)ptr);
    my_put_pointer((unsigned long)ptr);
    cr_assert_stdout_eq_str(expected);
}

Test(my_put_pointer, larger_address)
{
    char expected[20];
    unsigned long addr = 0x7ffeefbff5c0;

    cr_redirect_stdout();
    sprintf(expected, "%p", (void *)addr);
    my_put_pointer(addr);
    cr_assert_stdout_eq_str(expected);
}
