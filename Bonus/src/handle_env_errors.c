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
    my_putstr(cmd);
    my_putstr(msg);
    return 1;
}

static int check_invalid_chars(char *cmd, char **args)
{
    if (my_strchr(args[1], '=') != NULL)
        return env_error(cmd, ": Variable name must not contain '='\n");
    if (my_strchr(args[1], ' ') != NULL)
        return env_error(cmd, ": Variable name must not contain spaces\n");
    if (args[2] && my_strchr(args[2], '=') != NULL)
        return env_error(cmd, ": Variable value must not contain '='\n");
    return 0;
}

static int check_name_syntax(char *cmd, char **args)
{
    if (args[1][0] == '\0')
        return env_error(cmd, ": Variable name must not be empty\n");
    if (args[1][0] >= '0' && args[1][0] <= '9')
        return env_error(cmd, ": Variable name must not start with a digit\n");
    return check_invalid_chars(cmd, args);
}

static int check_arg_count(char *cmd, char **args, int x)
{
    if (!args[1])
        return env_error(cmd, ": Too few arguments\n");
    if (x == 1 && args[3])
        return env_error(cmd, ": Too many arguments\n");
    return 0;
}

int handle_env_errors(char **args, char ***env, int x)
{
    char *cmd = (x == 1) ? "setenv" : "unsetenv";

    if (*env == NULL)
        return env_error(cmd, ": Environment not initialized\n");
    if (check_arg_count(cmd, args, x) != 0)
        return 1;
    if (check_name_syntax(cmd, args) != 0)
        return 1;
    return 0;
}
