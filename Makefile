# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 11:26:50 by arashido          #+#    #+#              #
#    Updated: 2023/06/20 18:58:09 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c parsing_map.c parsing_error.c parsing_item.c\
			valid_map.c utils/gnl/gnl_utils.c utils/gnl/get_next_line_utils.c\
			utils/gnl/get_next_line.c utils.c keyhooks.c\

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

