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
        my_put_error(" (core dumped)");
    }
}

void handle_signal_status(int status)
{
    int signal_num = WTERMSIG(status);

    if (signal_num == SIGSEGV) {
        my_put_error("Segmentation fault");
        check_core_dump(status);
    } else if (signal_num == SIGFPE) {
        my_put_error("Floating point exception");
        check_core_dump(status);
        my_put_error("\n");
    } else {
        my_put_error("Command terminated by signal ");
        my_put_nbr_error(signal_num);
        my_put_error("\n");
    }
}

void handle_errors(int status)
{
    int exit_status = WEXITSTATUS(status);

    if (WIFEXITED(status) && exit_status != 0) {
        my_put_error("Command exited with status ");
        my_put_nbr_error(exit_status);
        my_put_error("\n");
    } else if (WIFSIGNALED(status)) {
        handle_signal_status(status);
    }
}
