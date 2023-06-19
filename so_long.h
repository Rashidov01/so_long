/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:41 by arashido          #+#    #+#             */
/*   Updated: 2023/06/19 21:50:25 by arashido         ###   ########.fr       */
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
# define SPACE "./images/floor.xpm"
# define COIN "./images/coin.xpm"
# define EXIT "./images/exit.xpm"

typedef struct s_game
{
	int		fd;
	int		row;
	char	**map;
	int		i;
	int		j;
	char	*line;
	char	**arr;
	int		col;
	char	*mlx;
	void	*img;
	int		p_x;
	int		p_y;
	int		size_x;
	int		size_y;
	int		*mlx_window;
}			t_game;

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
void		draw_img(t_game *game, char *path, int x, int y);
void		pick_img(t_game *game, char c, int x, int y);
void		draw_map(t_game *game);

#endif