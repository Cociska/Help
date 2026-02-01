/*
** EPITECH PROJECT, 2025
** my swap.c
** File description:
** a function that swaps the content
** of two integers, whose addresses
** are given as a parameter.
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
