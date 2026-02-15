/*
** EPITECH PROJECT, 2026
** Mini-Shell-1
** File description:
** mini_shell
*/

#ifndef MINI_SHELL_1_FUNCTIONS_H
    #define MINI_SHELL_1_FUNCTIONS_H

    #include <stdlib.h>   // malloc, free, exit
    #include <unistd.h>   /* getcwd, chdir, fork, execve,
                            access, isatty, read, write, close, getpid */
    #include <dirent.h>   // opendir, readdir, closedir
    #include <sys/stat.h> // stat, lstat, fstat
    #include <fcntl.h>    // open
    #include <stdio.h>    // getline, perror
    #include <string.h>   // strtok, strtok_r, strerror, strsignal
    #include <sys/wait.h> // wait, waitpid, wait3, wait4 + macros WIF...
    #include <signal.h>   // signal, kill
    #include <errno.h>    // errno

void print_prompt(void);
void execute_command(char **args, char **env);
void buildin_env(char **env);
int builtin_cd(char **env, char **args);

char *remove_newline(char *str);
char *get_env(char **env, char *name);
void strtab_free(char **tab);
void free_tab_n(char **tab, int n);
char *find_external_command(char *command, char **env);


#endif // MINI_SHELL_1_FUNCTIONS_H
