/*
** EPITECH PROJECT, 2025
** test_my_printf.c
** File description:
** testing my_printf.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_printf.h"

Test(my_printf, integer)
{
    cr_redirect_stdout();
    my_printf("%d", 5);
    cr_assert_stdout_eq_str("5");
}

Test(my_printf, flag_e)
{
    cr_redirect_stdout();
    my_printf("%e", 9.87654321);
    cr_assert_stdout_eq_str("9.876543e+00");
}

Test(my_printf, flag_maj_e)
{
    cr_redirect_stdout();
    my_printf("%E", 9.87654321);
    cr_assert_stdout_eq_str("9.876543E+00");
}

Test(my_printf, flag_u)
{
    cr_redirect_stdout();
    my_printf("%u", 12);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf, integer_whith_i)
{
    cr_redirect_stdout();
    my_printf("%i", 6);
    cr_assert_stdout_eq_str("6");
}

Test(my_printf, float_num)
{
    cr_redirect_stdout();
    my_printf("%f", 5.99);
    cr_assert_stdout_eq_str("5.990000");
}

Test(my_printf, char_c)
{
    cr_redirect_stdout();
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, string)
{
    cr_redirect_stdout();
    my_printf("%s", "Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(my_printf, percent)
{
    cr_redirect_stdout();
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, without_knowed_flag)
{
    cr_redirect_stdout();
    my_printf("%k");
    cr_assert_stdout_eq_str("%k");
}

Test(my_printf, oct)
{
    cr_redirect_stdout();
    my_printf("%o", 9);
    cr_assert_stdout_eq_str("11");
}

Test(my_printf, without_flags)
{
    cr_redirect_stdout();
    my_printf("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(my_printf, hexa)
{
    cr_redirect_stdout();
    my_printf("%x", 67);
    cr_assert_stdout_eq_str("43");
}

Test(my_printf, pointer)
{
    cr_redirect_stdout();
    my_printf("%p", 0);
    cr_assert_stdout_eq_str("(nil)");
}

Test(my_printf, many_flags)
{
    cr_redirect_stdout();
    my_printf("Char: %c, String: %s, Int: %d", 'Z', "Test", 42);
    cr_assert_stdout_eq_str("Char: Z, String: Test, Int: 42");
}

Test(my_printf, second_other_flag)
{
    cr_redirect_stdout();
    my_printf("Unsigned: %u, Sci: %e", 300, 12345.6789);
    cr_assert_stdout_eq_str("Unsigned: 300, Sci: 1.234568e+04");
}
