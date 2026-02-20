/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** spawn_new_terminal corrected
*/

#include "my.h"
#include "mini_shell.h"

static char **kitty_params(char *cwd, char *cmd)
{
    char **params;

    params = malloc(sizeof(char *) * 7);
    if (!params)
        return (0);
    params[0] = "kitty";
    params[1] = "--working-directory";
    params[2] = cwd;
    params[3] = "bash";
    params[4] = "-lc";
    params[5] = cmd;
    params[6] = NULL;
    return params;
}

static int build_cmd(char *cmd, int size, const char *path)
{
    int len;

    len = my_strlen("MYSH_SPAWNED=1 exec ") + my_strlen(path) + 1;
    if (len > size)
        return 0;
    cmd[0] = '\0';
    my_strcat(cmd, "MYSH_SPAWNED=1 exec ");
    my_strcat(cmd, path);
    return 1;
}

static int error_handling_spawn(char ***env, char *path, char *cmd, char *cwd)
{
    if (my_getenv(*env, "MYSH_SPAWNED"))
        return 0;
    if (!getcwd(cwd, PATH_MAX))
        return 0;
    if (!build_cmd(cmd, PATH_MAX * 2, path))
        return 0;
    return 1;
}

int spawn_new_terminal(char ***env, char *path)
{
    char cwd[PATH_MAX];
    char cmd[PATH_MAX * 2];
    pid_t pid;
    char **argv = kitty_params(cwd, cmd);

    if (error_handling_spawn(env, path, cmd, cwd) == 0)
        return 0;
    pid = fork();
    if (pid < 0)
        return 0;
    if (pid == 0) {
        execve("/usr/bin/kitty", argv, *env);
        perror("mysh: failed to launch kitty");
        exit(1);
    }
    return 1;
}
