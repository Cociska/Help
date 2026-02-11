/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** test2
*/

#include "mini_shell.h"

void shell(void)
{
    char *line = NULL;
    size_t cap = 0;
    ssize_t status;

    while (1) {
        print_prompt();
        status = getline(&line, &cap, stdin);
        if (exit_case(status, line))
            break;
    }
    free(line);
}

int main(int argc, char **argv, char **env)
{
    print_env(env);
    shell();
    (void)argc;
    (void)argv;
    return 0;
}
