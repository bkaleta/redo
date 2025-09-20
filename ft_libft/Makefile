# ===============================
# libft (statyczna biblioteka C)
# ===============================

NAME     := libft.a
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -std=c99 
AR       := ar
ARFLAGS  := rcs
RM       := rm -f

# --- tutaj wykluczamy main.c z biblioteki ---
SRCS_ALL := $(wildcard *.c)
SRCS     := $(filter-out main.c, $(SRCS_ALL))
OBJS     := $(SRCS:.c=.o)

# program testowy w tym samym folderze
TEST_BIN := libft_local_tests
TEST_SRC := main.c

.PHONY: all clean fclean re check run check-asan

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@echo "✔️  Created $@"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ====== Lokalny tester ======
$(TEST_BIN): $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) -I. $(TEST_SRC) $(NAME) -o $(TEST_BIN)
	@echo "✔️  Built $(TEST_BIN)"

check: $(TEST_BIN)
	@./$(TEST_BIN)

run: check

check-asan: CFLAGS += -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer
check-asan: clean $(TEST_BIN)
	ASAN_OPTIONS=detect_leaks=1 ./$(TEST_BIN)

clean:
	$(RM) $(OBJS)
	@echo "🧹 Object files removed"

fclean: clean
	$(RM) $(NAME) $(TEST_BIN)
	@echo "🗑️  $(NAME) and $(TEST_BIN) removed"

re: fclean all
