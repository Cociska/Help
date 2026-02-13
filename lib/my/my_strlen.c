/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
