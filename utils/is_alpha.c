/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** is_alpha
*/

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    if (c == '_')
        return 1;
    return 0;
}
