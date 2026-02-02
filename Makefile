## EPITECH PROJECT, 2024
## BSQ
## Clean Makefile inspired by yours

CC		= epiclang
CFLAGS		= -Werror -Wall -Wextra
TEST_CFLAGS	= --coverage -lcriterion

SRC_PATH	= src/
FILE_PATH	= src/file/
ALGO_PATH	= src/algo/
UTILS_PATH	= src/utils/
TESTS_PATH	= tests/
ASSET_PATH	= Assets/

BINARY		= setting_up
TEST_BIN	= unit_tests

SRC	= \
	$(SRC_PATH)main.c \
	$(FILE_PATH)read_file.c \
	$(FILE_PATH)parse_lines.c \
	$(ALGO_PATH)build_tab.c \
	$(ALGO_PATH)find_biggest_square.c \
	$(ALGO_PATH)fill_square.c \
	$(UTILS_PATH)my_strlen.c \
	$(UTILS_PATH)my_putchar.c \
	$(UTILS_PATH)my_putstr.c \
	$(UTILS_PATH)my_getnbr.c \
    $(ALGO_PATH)map_gen.c \
	$(UTILS_PATH)print_file.c

SRC_TEST	= \
	$(FILE_PATH)read_file.c \
	$(FILE_PATH)parse_lines.c \
	$(ALGO_PATH)build_tab.c \
	$(ALGO_PATH)find_biggest_square.c \
	$(ALGO_PATH)fill_square.c \
	$(UTILS_PATH)my_strlen.c \
	$(UTILS_PATH)my_putchar.c \
	$(UTILS_PATH)my_putstr.c \
	$(UTILS_PATH)print_file.c \
	$(UTILS_PATH)my_getnbr.c \
	$(ALGO_PATH)map_gen.c

OBJ	= $(SRC:.c=.o)

TESTS	= 	$(TESTS_PATH)test_setting_up.c \
			$(TESTS_PATH)tests_build_tab.c \
			$(TESTS_PATH)tests_my_putchar.c \
			$(TESTS_PATH)tests_my_putstr.c \
			$(TESTS_PATH)tests_my_strlen.c \
			$(TESTS_PATH)tests_parse_lines.c \
			$(TESTS_PATH)tests_print_file.c \
			$(TESTS_PATH)tests_find_biggest_square.c \
			$(TESTS_PATH)tests_read_file.c \
			$(TESTS_PATH)tests_map_gen.c \
			$(TESTS_PATH)tests_my_getnbr.c

$(BINARY): $(OBJ)
	@$(CC) -o $(BINARY) $(OBJ)
	@echo "Compiled (^_^)"

%.o: %.c
	@echo Compiling "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) *.gcda *.gcno *.txt
	@echo "Object files cleaned"

fclean: clean
	@rm -f $(BINARY) $(TEST_BIN)
	@echo "Full clean :3"

re: fclean $(BINARY)

unit_tests:
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $(SRC_TEST) $(TESTS) -o $(TEST_BIN) --coverage

run_tests: unit_tests
	./$(TEST_BIN)

test:
	cc $(CFLAGS) $(TEST_CFLAGS) $(SRC_TEST) $(TESTS) -o $(TEST_BIN) --coverage
	./$(TEST_BIN)
	gcovr --exclude tests/
