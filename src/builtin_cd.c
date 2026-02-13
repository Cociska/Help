/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** builtin_cd
*/

#include "my.h"
#include "mini_shell.h"

static int change_directory(const char *path)
{
    if (chdir(path) == -1) {
        perror("cd");
        return 1;
    }
    return 0;
}

int builtin_cd(char **env, char **args)
{
    if (!args[1] || my_strcmp(args[1], "~") == 0)
        return change_directory(get_env(env, "HOME"));
    if (my_strcmp(args[1], "-") == 0)
        return change_directory(get_env(env, "OLDPWD"));
    return change_directory(args[1]);
}
