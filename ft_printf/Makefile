# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 22:36:28 by kosakats          #+#    #+#              #
#    Updated: 2024/11/22 22:57:33 by kosakats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRCS		=	libft2/ft_putchar_fd.c libft2/ft_putstr_fd.c libft2/ft_putnbr_fd.c  ft_printf.c ft_putptr_fd.c ft_putnbr_u_fd.c ft_puthex_fd.c
INCLUDES	= 	-I./includes
OBJS		=    $(SRCS:.c=.o)
CC			=    cc
CFLAGS		=    -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus