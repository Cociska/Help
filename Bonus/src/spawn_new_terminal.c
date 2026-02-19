/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** spawn_new_terminal
*/

#include "my.h"
#include "mini_shell.h"

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

static int error_handling(char ***env, const char *path, char *cwd, char *cmd)
{
    if (!path)
        return 0;
    if (my_getenv(*env, "MYSH_SPAWNED"))
        return 0;
    if (!my_getenv(*env, "DISPLAY") && !my_getenv(*env, "WAYLAND_DISPLAY"))
        return 0;
    if (!getcwd(cwd, sizeof(cwd)))
        return 0;
    if (!build_cmd(cmd, sizeof(cmd), path))
        return 0;
    return 1;
}

int spawn_new_terminal(char ***env, const char *path)
{
    char cwd[PATH_MAX];
    char cmd[PATH_MAX * 2];
    pid_t pid;
    char *argv[] = {
        "kitty", "--working-directory", cwd,
        "bash", "-lc",
        cmd, NULL
    };

    if (error_handling(env, path, cwd, cmd) == 0)
        return 0;
    pid = fork();
    if (pid < 0)
        return 0;
    if (pid == 0) {
        execve("/usr/bin/kitty", argv, *env);
        _exit(1);
    }
    return 1;
}
