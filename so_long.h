/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:41 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:37:01 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libs/ft_printf/ft_printf.h"
# include "libs/gnl/get_next_line.h"
# include "mlx/mlx.h"
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

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

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
	int		exit_map;
	int		is_player;
	int		exit;
	int		valid[256][256];
	int		is_coin;
	int		is_exit;
	int		exit_y;
	int		exit_x;
}			t_game;

char		**ft_split(char *s, char c);
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
int			str_compare_fn(char *s1, char *s2);
void		graphics(t_game *game, char *path, int map_x, int map_y);
void		pick_image(t_game *game, char c, int x, int y);
void		draw_map(t_game *game);
void		close_window(t_game *game);
void		exit_game(t_game *game, int x, int y);
void		game_win(t_game *game);
int			moves(t_game *game, int x, int y);
int			key_hook(int keycode, t_game *game);
int			count_collactable(char **map);
void		find_player(t_game *game);
void		find_exit(t_game *game);
int			validcheck(t_game *game, int x, int y);
void		invalid_path_check(t_game *game, int x, int y);
void		free_and_exit(t_game *game);
void		hashmaker(t_game *game);
void		validchecker(t_game *game);
int			map_parsing_helper(char **map);
char		**get_map(char *str);
int			ft_map_parsing(char **av);
void		mainchecker(t_game *game);
#endif