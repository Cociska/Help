##
## EPITECH PROJECT, 2024
## libmy
## File description:
## Makefile for libmy
##

CC	= epiclang
CFLAGS	= -Werror -Wall -Wextra
CRITERION_FLAGS = --coverage -lcriterion
PATH_LIBMY	= lib/my/
PATH_LIBPRINTF	= lib/my_printf/
PATH_TESTS = tests/

NAME	= libmy.a

SRC	= $(PATH_LIBMY)my_compute_power_rec.c \
	  $(PATH_LIBMY)my_compute_square_root.c \
	  $(PATH_LIBMY)my_find_prime_sup.c \
	  $(PATH_LIBMY)my_getnbr.c \
	  $(PATH_LIBMY)my_isneg.c \
	  $(PATH_LIBMY)my_is_prime.c \
	  $(PATH_LIBMY)my_putchar.c \
	  $(PATH_LIBMY)my_put_nbr.c \
	  $(PATH_LIBMY)my_putstr.c \
	  $(PATH_LIBMY)my_revstr.c \
	  $(PATH_LIBMY)my_showmem.c \
	  $(PATH_LIBMY)my_showstr.c \
	  $(PATH_LIBMY)my_sort_int_array.c \
	  $(PATH_LIBMY)my_strcapitalize.c \
	  $(PATH_LIBMY)my_strcat.c \
	  $(PATH_LIBMY)my_strcmp.c \
	  $(PATH_LIBMY)my_strcpy.c \
	  $(PATH_LIBMY)my_str_isalpha.c \
	  $(PATH_LIBMY)my_str_islower.c \
	  $(PATH_LIBMY)my_str_isnum.c \
	  $(PATH_LIBMY)my_str_isprintable.c \
	  $(PATH_LIBMY)my_str_isupper.c \
	  $(PATH_LIBMY)my_strlen.c \
	  $(PATH_LIBMY)my_strlowcase.c \
	  $(PATH_LIBMY)my_strncat.c \
	  $(PATH_LIBMY)my_strncmp.c \
	  $(PATH_LIBMY)my_strncpy.c \
	  $(PATH_LIBMY)my_strstr.c \
	  $(PATH_LIBMY)my_strupcase.c \
	  $(PATH_LIBMY)my_swap.c \
	  $(PATH_LIBPRINTF)my_put_float.c \
      $(PATH_LIBPRINTF)my_put_nbr_uint.c \
      $(PATH_LIBPRINTF)my_put_oct.c \
      $(PATH_LIBPRINTF)my_put_hex.c \
      $(PATH_LIBPRINTF)my_printf.c \
	  $(PATH_LIBPRINTF)my_printf_format.c \
	  $(PATH_LIBPRINTF)my_put_pointer.c \
	  $(PATH_LIBPRINTF)my_isinf.c \
	  $(PATH_LIBPRINTF)my_isnan.c \
	  $(PATH_LIBPRINTF)my_put_ieee.c \
	  $(PATH_LIBPRINTF)my_put_float_sci.c \
	  $(PATH_LIBPRINTF)my_put_bin.c

COVERAGE_SRC 	= \
    $(PATH_LIBMY)my_putchar.c \
    $(PATH_LIBMY)my_putstr.c \
    $(PATH_LIBMY)my_put_nbr.c \
    $(PATH_LIBPRINTF)my_isinf.c \
    $(PATH_LIBPRINTF)my_isnan.c \
    $(PATH_LIBPRINTF)my_put_hex.c \
    $(PATH_LIBPRINTF)my_put_nbr_uint.c \
    $(PATH_LIBPRINTF)my_put_oct.c \
    $(PATH_LIBPRINTF)my_put_pointer.c \
    $(PATH_LIBPRINTF)my_put_float.c \
    $(PATH_LIBPRINTF)my_put_float_sci.c \
    $(PATH_LIBPRINTF)my_put_ieee.c \
	$(PATH_LIBPRINTF)my_put_bin.c \
    $(PATH_LIBPRINTF)my_printf.c \
    $(PATH_LIBPRINTF)my_printf_format.c


TESTS_SRC  = $(PATH_TESTS)test_my_put_float.c \
         $(PATH_TESTS)test_my_put_float_sci.c \
	     $(PATH_TESTS)test_my_put_hex.c \
	     $(PATH_TESTS)test_my_printf.c \
	     $(PATH_TESTS)test_my_put_nbr.c \
	     $(PATH_TESTS)test_my_putstr.c \
	     $(PATH_TESTS)test_my_put_oct.c \
	     $(PATH_TESTS)test_my_put_pointer.c \
	     $(PATH_TESTS)test_my_put_ieee.c \
	     $(PATH_TESTS)test_my_isinf.c \
		 $(PATH_TESTS)test_my_put_nbr_uint.c

TEST_BIN   = unit_tests

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Compiled (^_^)"

%.o: %.c
	@echo Compiling \"$<\"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

tclean:
	@rm -f *.gcda *.gcno unit_tests
	@echo "Test cleaned :O"

fclean:	clean
	@rm -f $(NAME)
	@echo "Cleaned :3"

re: clean all
	@echo "Recompiled ;)"

compile:all
	@$(CC) $(LIB_PRINTF)my_printf.c $(NAME)
	@echo "a.out created :D"

unit_tests: $(NAME)
	@$(CC) -o $(TEST_BIN) $(TESTS_SRC) $(COVERAGE_SRC) $(CRITERION_FLAGS)

compile_file:
	@$(CC) $(CFLAGS) -c $(FILE) -o $(FILE:.c=.o)
	@ar rc $(NAME) $(FILE:.c=.o)
	@echo "Recompiled $(FILE) and updated $(NAME) (O_O)"

test_main:all
	@gcc main.c $(NAME)
	@./a.out
	@echo "Tests run <(^_^)>"

tests_run: unit_tests
	@./$(TEST_BIN)
	@echo "All tests passed! (^_^)v"

coverage: unit_tests
	@./$(TEST_BIN)
	coverage:
	@gcovr -r . --exclude tests/
	@echo "Coverage generated :D"