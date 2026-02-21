/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** handle_env_errors
*/

#include "my.h"
#include "mini_shell.h"

static int env_error(char *cmd, char *msg)
{
    my_put_error(cmd);
    my_put_error(msg);
    return 1;
}

static int check_name_syntax(char *cmd, char **args)
{
    int i;

    if (args[1][0] == '\0')
        return env_error(cmd, ": Variable name must not be empty.\n");
    if (args[1][0] >= '0' && args[1][0] <= '9')
        return env_error(cmd, ": Variable name must begin with a letter.\n");
    for (i = 0; args[1][i] != '\0'; i++) {
        if (!is_alpha(args[1][i])) {
            my_put_error(cmd);
            my_put_error(": Variable name must contain ");
            my_put_error("only alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

static int check_arg_count(char *cmd, char **args, int x)
{
    if (!args[1])
        return env_error(cmd, ": Too few arguments.\n");
    if (x == 1 && args[3])
        return env_error(cmd, ": Too many arguments.\n");
    return 0;
}

int handle_env_errors(char **args, char ***env, int x)
{
    char *cmd;

    if (x == 1)
        cmd = "setenv";
    else
        cmd = "unsetenv";
    if (*env == NULL)
        return env_error(cmd, ": Environment not initialized.\n");
    if (check_arg_count(cmd, args, x) != 0)
        return 1;
    if (x == 1 && check_name_syntax(cmd, args) != 0)
        return 1;
    return 0;
}
