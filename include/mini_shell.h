/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** mini_shell
*/


#ifndef MINI_SHELL_1_FUNCTIONS_H
    #define MINI_SHELL_1_FUNCTIONS_H

    #include <stdlib.h>     // malloc, free, exit
    #include <unistd.h>     /* getcwd, chdir, fork, execve,
                            access, isatty, read, write, close, getpid */
    #include <dirent.h>     // opendir, readdir, closedir
    #include <sys/stat.h>   // stat, lstat, fstat
    #include <fcntl.h>      // open
    #include <stdio.h>      // getline, perror
    #include <string.h>     // strtok, strtok_r, strerror, strsignal
    #include <sys/wait.h>   // wait, waitpid, wait3, wait4 + macros WIF...
    #include <signal.h>     // signal, kill
    #include <errno.h>      // errno
    #include "my.h"         /* my_putchar, my_putstr, my_strcmp, my_strlen
                            my_putcolors, is_exit */
    #include "colors.h"     // colors macro

int is_exit(char *line);
int exit_case(ssize_t status, char *line);
void print_prompt(void);
char *get_path(char **env);
void print_env(char **env);

#endif //MINI_SHELL_1_FUNCTIONS_H
