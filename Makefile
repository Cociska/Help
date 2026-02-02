##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile for secured
##

C_RESET   = \033[0m
C_BOLD    = \033[1m

C_GREEN   = \033[32m
C_BLUE    = \033[34m
C_CYAN    = \033[36m
C_YELLOW  = \033[93m
C_PURPLE  = \033[35m
C_ORANGE  = \033[38;5;208m

CC		= 	epiclang

SRC = 	src/main.c \
		src/parsing.c \
		src/help.c \
		src/auth.c \
		src/accounts.c \
		src/policy.c

OBJ		= 	$(SRC:.c=.o)

NAME      = my_sudo

CFLAGS	= 	-Wall -Wextra -W
LDLIBS  =   -lcrypt

all: $(NAME)


$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDLIBS)
	@echo "$(C_GREEN)Compiled (^_^)$(C_RESET)"

%.o: %.c
	@echo "$(C_BLUE)Compiling $<$(C_RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@clear
	@rm -f $(OBJ)
	@echo "$(C_BLUE)Object files removed :D$(C_RESET)"
	@rm -f *.gcda *.gcno *.gcov
	@echo "$(C_BLUE)Test artifacts cleaned ;)$(C_RESET)"
	@rm -rf html_report coverage.info coverage_filtered.info
	@echo "$(C_BLUE)Coverage files deleted :P$(C_RESET)"

fclean: clean
	@rm -f $(NAME) $(TEST_BIN)
	@echo "$(C_CYAN)Binary removed <_<$(C_RESET)"

re: fclean all
	@echo "$(C_BOLD)$(C_YELLOW)Project rebuilt successfully \\o/$(C_RESET)"

.PHONY: all clean fclean re
