/*
** EPITECH PROJECT, 2025
** my_printf_format.c
** File description:
** format handling (width, padding)
*/

#include "../../include/my.h"
#include "../../include/my_printf.h"

int get_width(const char *format, int *i)
{
    int width = 0;

    while (format[*i] >= '0' && format[*i] <= '9') {
        width = width * 10 + (format[*i] - '0');
        (*i)++;
    }
    return (width);
}

static int get_int_len(int nb)
{
    int len = 1;
    int n = nb;

    if (n < 0) {
        len = 2;
        n = -n;
    }
    if (n == 0)
        return (1);
    while (n / 10 != 0) {
        len++;
        n /= 10;
    }
    return (len);
}

static int get_hex_len(int nb)
{
    int len = 1;

    if (nb == 0)
        return (1);
    while (nb / 16 != 0) {
        len++;
        nb /= 16;
    }
    return (len);
}

static int get_oct_len(unsigned nb)
{
    int len = 1;

    if (nb == 0)
        return (1);
    while (nb / 8 != 0) {
        len++;
        nb /= 8;
    }
    return (len);
}

int pad_nbr(int nb, int width)
{
    int count = 0;
    int len = get_int_len(nb);

    if (width > len) {
        for (int i = len; i < width; i++)
            count += my_putchar(' ');
    }
    count += my_put_nbr(nb);
    return (count);
}

int pad_hex(int nb, int width, int cap)
{
    int count = 0;
    int len = get_hex_len(nb);

    if (width > len) {
        for (int i = len; i < width; i++)
            count += my_putchar(' ');
    }
    count += my_put_hex(nb, cap);
    return (count);
}

int pad_oct(unsigned nb, int width)
{
    int count = 0;
    int len = get_oct_len(nb);

    if (width > len) {
        for (int i = len; i < width; i++)
            count += my_putchar(' ');
    }
    count += my_put_oct(nb);
    return (count);
}
