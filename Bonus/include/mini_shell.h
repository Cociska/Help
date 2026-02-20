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
    #include <linux/limits.h> // PATH_MAX

void execute_command(char **args, char **env);
void buildin_env(char **env);
int builtin_cd(char **env, char **args);
int builtin_setenv(char ***env, char **args);

void print_prompt(void);
int spawn_new_terminal(char ***env, char *shell_path);
char *remove_newline(char *str);
char *my_getenv(char **env, char *name);
void strtab_free(char **tab);
void free_tab_n(char **tab, int n);
char *find_external_command(char *command, char **env);
int builtin_unsetenv(char ***env, char **args);
int is_builtin(char *command);
void handle_errors(int status);
int handle_env_errors(char **args, char ***env, int x);
char *remove_path_start(char *path);

#endif // MINI_SHELL_1_FUNCTIONS_H
