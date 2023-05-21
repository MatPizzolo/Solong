NAME = so_long

SRCS_DIR = ./src
GNL_DIR = ./gnl

SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/player.c $(SRCS_DIR)/utils.c $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
	$(SRCS_DIR)/game_starter.c $(SRCS_DIR)/put_xpm.c $(SRCS_DIR)/map.c $(SRCS_DIR)/is_playable.c $(SRCS_DIR)/check_win.c \
	$(SRCS_DIR)/close_window.c $(SRCS_DIR)/check_last_line.c $(SRCS_DIR)/utils_two.c $(SRCS_DIR)/is_playable_two.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libft_printf.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit \
	-L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -o $(NAME)

%.o: %.c ./libft/libft.h ./ft_printf/libft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all
