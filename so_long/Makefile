SHELL := /bin/bash

# ===================== Project =====================
NAME    := so_long
CC      := gcc

# ===================== Paths  ======================
MLIBX       := minilibx-linux
MLX_URL     := https://github.com/42Paris/minilibx-linux.git

LIBFT_DIR   := ft_libft
LIBFT_A     := $(LIBFT_DIR)/libft.a
LIBFT_INC   := $(LIBFT_DIR)

# ---- Flags ----
CFLAGS  := -Wall -Wextra -Werror -Iincludes -Iincludes/gnl -Iincludes/mlx -I$(MLIBX) -I$(LIBFT_INC)
MXFLAGS := -L$(MLIBX) -lmlx_Linux -lX11 -lXext -lm
LFTFLAGS:= -L$(LIBFT_DIR) -lft

# ===================== Sources (bez wildcardów) =====================
SRC := \
srcs/main.c \
srcs/gnl/get_next_line.c \
srcs/gnl/get_next_line_utils.c
# srcs/game.c \
# srcs/map.c \
# srcs/render.c \

OBJ := $(SRC:.c=.o)

# ===================== Pretty printing =====================
msg  = printf "\033[1m%s\033[0m\n" "$(1)"
ok   = printf "  \033[32m✔\033[0m %s\n" "$(1)"
run  = printf "  \033[34m›\033[0m %s\n" "$(1)"
warn = printf "  \033[33m!\033[0m %s\n" "$(1)"
err  = printf "  \033[31m✖\033[0m %s\n" "$(1)"

# ===================== Rules =====================
all: premsg $(MLIBX)/libmlx_Linux.a $(LIBFT_A) $(NAME)
	@$(call ok,Build complete: $(NAME))

premsg:
	@$(call msg,Building $(NAME)…)

$(NAME): $(OBJ)
	@$(call run,Linking $(NAME)…)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(MXFLAGS) $(LFTFLAGS) \
	 && $(call ok,Linked $(NAME)) \
	 || { $(call err,Link failed); exit 1; }

%.o: %.c
	@$(call run,CC $<)
	@$(CC) $(CFLAGS) -c $< -o $@ \
	 || { $(call err,Compile failed: $<); exit 1; }

# ===================== MiniLibX: =====================
$(MLIBX):
	@$(call run,Downloading MLX → $(MLIBX)…)
	@{ git clone --depth=1 $(MLX_URL) $(MLIBX) >/dev/null 2>&1 \
	  && $(call ok,Downloading MLX DONE) \
	  || $(call ok,MLX already present); }

$(MLIBX)/libmlx_Linux.a: | $(MLIBX)
	@$(call run,Building MLX…)
	@$(MAKE) -C $(MLIBX) >/dev/null 2>&1 \
	 && $(call ok,MLX build DONE) \
	 || { $(call err,MLX build failed); exit 1; }

# ====================== Libft ======================
$(LIBFT_A):
	@$(call run,Building libft…)
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1 \
	 && $(call ok,libft build DONE) \
	 || { $(call err,libft build failed); exit 1; }

# ===================== Cleaning =====================
clean:
	@$(call run,Cleaning objects…)
	@$(RM) -f $(OBJ)
	@[ ! -d $(MLIBX) ] || { $(MAKE) -C $(MLIBX) clean >/dev/null 2>&1; $(call ok,MLX objects cleaned); }
	@[ ! -d $(LIBFT_DIR) ] || { $(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1; $(call ok,libft objects cleaned); }

fclean: clean
	@$(call run,Removing binary and libraries…)
	@$(RM) -f $(NAME)
	@{ test -f "$(LIBFT_A)" && $(RM) -f "$(LIBFT_A)" || true; }
	@rm -rf "$(MLIBX)"
	@$(call ok,Full clean DONE)

re: fclean all

.PHONY: all clean fclean re premsg
