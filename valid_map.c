/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:14:01 by arashido          #+#    #+#             */
/*   Updated: 2023/06/15 21:09:08 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (1);
}

// void	draw_img(t_game *game, char *path, int x, int y)
// {
// 	int	size;

// 	size = 64;
// 	x = x * size;
// 	y = y * size;
// 	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
// 	if (!game->img)
// 		exit(1);
// 	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x, y);
// 	mlx_destroy_image(game->mlx, game->img);
// }

// void	pick_img(t_game *game, char c, int x, int y)
// {
// 	if (c == '1')
// 		draw_img(game, WALL, x, y);
// 	else if (c == '0')
// 		draw_img(game, SPACE, x, y);
// 	else if (c == 'C')
// 		draw_img(game, COIN, x, y);
// 	else if (c == 'E')
// 		draw_img(game, EXIT, x, y);
// 	else if (c == 'P')
// 	{
// 		draw_img(game, ME, x, y);
// 		game->p_x = x;
// 		game->p_y = y;
// 	}
// }

// void	draw_map(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (game->mapcheck[y])
// 	{
// 		x = 0;
// 		while (game->mapcheck[y][x])
// 		{
// 			pick_img(game, game->mapcheck[y][x], x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	close_window(t_game *game)
// {
// 	mlx_clear_window(game->mlx, game->mlx_win);
// 	mlx_destroy_window(game->mlx, game->mlx_win);
// 	free(game->map);
// 	ft_free_arr(game->mapcheck);
// 	exit(0);
// }
