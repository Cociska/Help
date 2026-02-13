/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** my.h
*/

#ifndef MINI_SHELL_1_MY_H
    #define MINI_SHELL_1_MY_H

    #include <unistd.h>     // write
    #include <stdlib.h>     // malloc, free

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char **my_str_to_word_array(const char *str);
char *my_strdup(const char *src);
char **my_strdup_tab(char **tab);

#endif //MINI_SHELL_1_MY_H
