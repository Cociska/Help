/*
** EPITECH PROJECT, 2025
** Setting_up
** File description:
** tests_read_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"
#include <stdio.h>

Test(file, read_file_basic)
{
    FILE *f = fopen("tmp2.txt", "w");
    fputs("line1\nline2\n", f);
    fclose(f);

    char **buf = read_file("tmp2.txt");
    cr_assert_not_null(buf);
    free(buf);
}

Test(file, read_file_nonexistent)
{
    char **res = read_file("file_that_does_not_exist.txt");

    cr_assert_null(res);
}
