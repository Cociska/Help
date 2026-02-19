/*
** EPITECH PROJECT, 2026
** handle_errors.c
** File description:
** handle_errors
*/

#include "my.h"
#include "mini_shell.h"

void check_core_dump(int status)
{
    if (WCOREDUMP(status)) {
        my_putstr(" (core dumped)");
    }
}

void handle_signal_status(int status)
{
    int signal_num = WTERMSIG(status);

    if (signal_num == SIGSEGV) {
        my_putstr("Segmentation fault");
        check_core_dump(status);
        my_putchar('\n');
    } else if (signal_num == SIGFPE) {
        my_putstr("Floating point exception");
        check_core_dump(status);
        my_putchar('\n');
    } else {
        my_putstr("Command terminated by signal ");
        my_put_nbr(signal_num);
        my_putchar('\n');
    }
}

void handle_errors(int status)
{
    int exit_status = WEXITSTATUS(status);

    if (WIFEXITED(status) && exit_status != 0) {
        my_putstr("Command exited with status ");
        my_put_nbr(exit_status);
        my_putchar('\n');
    } else if (WIFSIGNALED(status)) {
        handle_signal_status(status);
    }
}
