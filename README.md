📝 Project my_printf :

This project involves creating a custom implementation of the printf function in C, following the C99 standard. The objective is to replicate the functionality of the standard printf, which handles formatted output, without implementing internal buffering. The custom printf should accept variable arguments, parse the format string, and print the appropriate output to the terminal.

We share our task on Trello, you can check theme [here](https://trello.com/invite/b/68efcca9a68126fd41f07fae/ATTI71a4e9ad58a34cdec8c59166f51032eaFA8951A2/project-myprintf)

Makefile commands :

make : compile all files on lib/my & lib/my_printf, and create a libmy.a file on root

make clean : remove all .o files

make tclean : remove all .gcda .gcno and also the binary named unit_tests

make fclean : do "make clean" command and also remove the libmy.a file on root

make re : remove all .o files and do "make" command

make compile : create a.out file of my_printf.c

make unit_tests : do "fclean" & "libmy.a" commands and then run the tests with libmy.a

make compile_file FILE="file path" : recompile a specific file (faster than recompiling all files)

make test_main : "make compile" command but running with the main at root (for tests)