CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
NAME := cub3D
LIBFT := libft/libft.a
FLAGLFT := -Llibft -lft
MINILIB := minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz
HEADER := -Iinc -Ilibft
RM := rm -rf

SRC_DIR := src/
OBJ_DIR := obj/

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(FLAGLFT) $(MINILIB) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
