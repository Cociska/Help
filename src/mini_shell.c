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
    char **args;
    size_t cap = 0;
    ssize_t status;

    while (1) {
        print_prompt();
        status = getline(&line, &cap, stdin);
        if (exit_case(status, line))
            break;
        if (line[status - 1] == '\n')
            line[status - 1] = '\0';
        args = my_str_to_word_array(line);
        execute_command(args, env);
        free(args);
    }
    free(line);
}

int main(int argc, char **argv, char **env)
{
    char **env_copy = NULL;

    (void)argc;
    (void)argv;
    if (!env || !env[0]) {
        my_putstr("No environment variables found.\n");
        return 1;
    }
    env_copy = my_strdup_tab(env);
    if (!env_copy) {
        my_putstr("Failed to copy environment variables.\n");
        return 1;
    }
    shell(env_copy);
    strtab_free(env_copy);
    return 0;
}
