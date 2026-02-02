#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/setting_up.h"

Test(utils, print_file_basic)
{
    int fd = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    write(fd, "HELLO", 5);
    close(fd);
    cr_redirect_stdout();
    print_file("tmp.txt");
    fflush(stdout);
    cr_assert_stdout_eq_str("HELLO");
    remove("tmp.txt");
}
