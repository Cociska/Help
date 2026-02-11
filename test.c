/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** test
*/

#include <stdlib.h>     // malloc, free, exit
#include <unistd.h>     // getcwd, chdir, fork, execve, access, isatty
#include <dirent.h>     // opendir, readdir, closedir
#include <sys/stat.h>   // stat, lstat, fstat
#include <fcntl.h>      // open
#include <stdio.h>      // getline, perror
#include <string.h>     // strtok, strtok_r, strerror, strsignal
#include <sys/wait.h>   // wait, waitpid, wait3, wait4 + macros WIF...
#include <signal.h>     // signal, kill
#include <errno.h>      // errno

static void execve_test(void)
{
    char *argv[] = {"ls", "-l", NULL};
    extern char **environ;

    for (int i = 0; i < 60; i++)
        printf("_");
    printf("\n\n");
    printf("execve test : \n\n");
    execve("/bin/ls", argv, environ);
    perror("execve");
}

static void getcwd_test(void)
{
    char cwd[4096];

    if (!getcwd(cwd, sizeof(cwd)))
        perror("getcwd");
    else
        printf("%s\n", cwd);
}

int main(void)
{
    execve_test();
    getcwd_test();
    return 0;
}
