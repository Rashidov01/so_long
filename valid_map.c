/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:14:01 by arashido          #+#    #+#             */
/*   Updated: 2023/06/23 01:13:18 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graphics(t_game *game, char *path, int map_x, int map_y)
{
	int	size;

	size = 64;
	map_x = map_x * size;
	map_y = map_y * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	if (!game->img)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, map_x, map_y);
	mlx_destroy_image(game->mlx, game->img);
}

void	pick_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
		graphics(game, WALL, x, y);
	else if (c == '0')
		graphics(game, SPACE, x, y);
	else if (c == 'E')
		graphics(game, EXIT, x, y);
	else if (c == 'C')
		graphics(game, COIN, x, y);
	else if (c == 'P')
	{
		graphics(game, ME, x, y);
		game->position_x = x;
		game->position_y = y;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			pick_image(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->map);
	exit(0);
}
