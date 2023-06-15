/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:41 by arashido          #+#    #+#             */
/*   Updated: 2023/06/15 21:12:04 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "utils/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "./images/wall.xpm"
# define ME "./images/player.xpm"
# define SPACE "./images/wall.xpm"
# define COIN "./images/coin.xpm"
# define EXIT "./images/finish.xpm"

typedef struct s_game
{
	int		fd;
	int		row;
	char	**map;
	int		i;
	int		j;
	char	*line;
	char	**arr;
}			t_game;

typedef struct s_data
{
	int		row;
	int		col;
	char	**map;
	void	*mlx;
	void	*mlx_win;
}			t_data;

typedef struct s_data1
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data1;

int			file_check(char *str);
int			file_check_permission(char *str);
int			check_exit(char **map);
int			get_row(char *str);
int			get_row_count(char **map);
int			check_collectible(char **map);
int			check_start(char **map);
int			check_border(char **map);
int			check_character(char *str);
int			check_extra_character(char **map);
int			check_map_rectangle(char **map);
int			check_line(char *str, char c);
void		ft_free_arr(char **p);
int			str_compare(char *s1, char *s2);
int			print_map(char **str);

#endif