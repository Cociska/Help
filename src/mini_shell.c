/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** test2
*/

#include "my.h"
#include "mini_shell.h"

static void shell(char **env)
{
    char *line = NULL;
    char **args;
    size_t cap = 0;

    while (1) {
        my_putstr(" >$ ");
        if (getline(&line, &cap, stdin) == -1){
            free(line);
            return;
        }
        if (line[0] == '\n')
            continue;
        line = remove_newline(line);
        args = my_str_to_word_array(line);
        execute_command(args, &env, line);
        strtab_free(args);
    }
    free(line);
}

int main(int argc, char **argv, char **env)
{
    char **env_copy = NULL;

    (void)argc;
    (void)argv;
    if (!env || !env[0])
        return 1;
    env_copy = my_strdup_tab(env);
    if (!env_copy)
        return 1;
    shell(env_copy);
    strtab_free(env_copy);
    return 0;
}
