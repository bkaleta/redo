# ===============================
# libft (statyczna biblioteka C)
# ===============================

NAME     := libft.a
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -std=c99
AR       := ar
ARFLAGS  := rcs
RM       := rm -f

# ---- LISTY ŹRÓDEŁ (uzupełnij!) ----
BASE_SRCS := \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

BONUS_SRCS := \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

# --- wybór SRCS zależnie od celu ---
ifdef WITH_BONUS
SRCS := $(BASE_SRCS) $(BONUS_SRCS)
else
SRCS := $(BASE_SRCS)
endif

OBJS := $(SRCS:.c=.o)

# program testowy w tym samym folderze
TEST_BIN := libft_local_tests
TEST_SRC := main.c

.PHONY: all bonus clean fclean re check run check-asan

all: $(NAME)

bonus: WITH_BONUS=1
bonus: $(NAME)
	@echo "✨ Built $(NAME) with BONUS"

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "✔️  Created $@"

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

# ====== Lokalny tester ======
$(TEST_BIN): $(NAME) $(TEST_SRC)
	@$(CC) $(CFLAGS) -I. $(TEST_SRC) $(NAME) -o $(TEST_BIN)
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
