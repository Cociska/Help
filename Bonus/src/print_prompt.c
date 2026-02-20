/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** print_prompt
*/

#include "my.h"
#include "mini_shell.h"
#include "colors.h"

void print_prompt(void)
{
    char *cwd = getcwd(NULL, 0);
    char *prompt;

    if (cwd == NULL)
        return;
    prompt = remove_path_start(cwd);
    my_putcolor(BLUE, prompt, 1);
    free(cwd);
    my_putstr(" >$ ");
}
