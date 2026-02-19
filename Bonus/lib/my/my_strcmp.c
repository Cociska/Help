/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] && s2[i] && (s1[i] == s2[i]); i++);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
