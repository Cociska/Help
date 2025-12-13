CC = epiclang
CFLAGS = -Wall -Wextra -Werror
CSFMLFLAGS = -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

SRC_PATH = src/
TESTS_PATH = tests/
UTILS_PATH = utils/

SRC = 	$(SRC_PATH)helper.c \
		$(UTILS_PATH)my_strlen.c \
		$(UTILS_PATH)my_strcmp.c \
		$(SRC_PATH)window.c \
		$(SRC_PATH)main.c

SRC_TESTS =	$(TESTS_PATH)test_my_radar.c

OBJ = $(SRC:.c=.o)

NAME = my_radar

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CSFMLFLAGS)
	@echo "Compiled (^_^)"

%.o: %.c
	@echo Compiling "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) *.gcda *.gcno *.gcov
	@echo "cleaned ^^"

fclean: clean
	@rm -f $(NAME)
	@echo "Full clean :3"

re: fclean all

run: $(BINARY)
	@./$(NAME)
	@echo "Success !"