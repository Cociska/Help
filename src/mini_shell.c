/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** test2
*/

#include "my.h"
#include "mini_shell.h"

void shell(char **env)
{
    char *line = NULL;
    size_t cap = 0;
    ssize_t status;
    char **args;

    while (1) {
        print_prompt();
        status = getline(&line, &cap, stdin);
        if (exit_case(status, line))
            break;
        args = my_str_to_word_array(line);
        execute_command(args, env);
        free(args);
    }
    free(line);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    shell(env);
    return 0;
}
