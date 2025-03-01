# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:52:51 by kosakats          #+#    #+#              #
#    Updated: 2025/02/21 21:57:04 by kosakats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = src/main.c \
		src/get_map.c \
		src/map_check.c \
		src/get_image.c \
		src/player_move.c \
		src/bfs_check.c \
		src/main_init.c \
		src/get_map_utils.c \
		src/bfs_check._utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_puthex_fd.c \
		ft_printf/ft_putnbr_u_fd.c \
		ft_printf/ft_putptr_fd.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Imlx -Ilibft -Iget_next_line -Ift_printf
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lGL
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT_LIB = $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

