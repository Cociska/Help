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
    char *pwd = getcwd(NULL, 0);
    char *target = NULL;
    int result = 0;
    char *setenv_args[4] = {"setenv", "OLDPWD", pwd, NULL};

    if (!pwd) {
        perror("getcwd");
        return 1;
    }
    if (!args[1] || my_strcmp(args[1], "~") == 0)
        target = my_getenv(env, "HOME");
    else if (my_strcmp(args[1], "-") == 0)
        target = my_getenv(env, "OLDPWD");
    else
        target = args[1];
    result = change_directory(target);
    if (result == 0)
        builtin_setenv(&env, setenv_args);
    free(pwd);
    return result;
}
