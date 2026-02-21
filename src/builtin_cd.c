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

static void update_pwd(char ***env, char *old_pwd)
{
    char *new_pwd = getcwd(NULL, 0);
    char *setenv_old[4];
    char *setenv_new[4];

    setenv_old[0] = "setenv";
    setenv_old[1] = "OLDPWD";
    setenv_old[2] = old_pwd;
    setenv_old[3] = NULL;
    builtin_setenv(env, setenv_old);
    if (new_pwd) {
        setenv_new[0] = "setenv";
        setenv_new[1] = "PWD";
        setenv_new[2] = new_pwd;
        setenv_new[3] = NULL;
        builtin_setenv(env, setenv_new);
        free(new_pwd);
    }
}

int builtin_cd(char ***env, char **args)
{
    char *pwd = getcwd(NULL, 0);
    char *target = NULL;
    int result = 0;

    if (!pwd) {
        perror("getcwd");
        return 1;
    }
    if (!args[1] || my_strcmp(args[1], "~") == 0)
        target = my_getenv(*env, "HOME");
    else if (my_strcmp(args[1], "-") == 0)
        target = my_getenv(*env, "OLDPWD");
    else
        target = args[1];
    result = change_directory(target);
    if (result == 0)
        update_pwd(env, pwd);
    free(pwd);
    return result;
}
