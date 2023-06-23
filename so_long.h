/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:41 by arashido          #+#    #+#             */
/*   Updated: 2023/06/23 18:14:04 by arashido         ###   ########.fr       */
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
# define EXITEXIT "./img/exit_exit.xpm"

# define KEY_ESC 53;
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

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
	int		position_x;
	int		position_y;
	int		size_x;
	int		size_y;
	int		*mlx_win;
	int		coin;
	int		moves;
	int		x;
	int		y;
	int		coins;
	int		markexit;
	int		is_player;
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
void		graphics(t_game *game, char *path, int map_x, int map_y);
void		pick_image(t_game *game, char c, int x, int y);
void		draw_map(t_game *game);
void		close_window(t_game *game);
void		mark_exit(t_game *game, int x, int y);
void		win(t_game *game);
int			moves(t_game *game, int x, int y);
int			key_hook(int keycode, t_game *game);
int			count_collactable(char **map);
void		free_and_exit(t_game *game);
#endif