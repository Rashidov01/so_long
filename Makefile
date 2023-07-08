# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 11:26:50 by arashido          #+#    #+#              #
#    Updated: 2023/07/08 20:41:44 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c parsing_map.c parsing_error.c parsing_item.c error_messages.c\
			valid_path.c game_utils.c game_keyhooks.c \
			parsing_helper.c invalid_path.c\
			libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c\
			libs/ft_printf/ft_printf.c libs/ft_printf/ft_hex.c\
			libs/ft_printf/ft_putchar.c libs/ft_printf/ft_putnbr.c\
			libs/ft_printf/ft_putstr.c libs/ft_printf/ft_putund.c libs/ft_printf/print_pointer.c \

OBJ	= $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = so_long

$(NAME): $(OBJ)
		$(MAKE) -C MLX
		gcc -W -W -W $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -D BUFFER_SIZE=1 -Imlx -c $< -o $@

all:	$(NAME)


clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx
fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all clean fclean re

