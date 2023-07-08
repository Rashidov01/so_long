/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:48:59 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:39:46 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	y;
	int	x;

	game->is_player = 0;
	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'P')
			{
				game->position_x = x;
				game->position_y = y;
				game->is_player++;
			}
			x++;
		}
		y++;
	}
}

void	find_exit(t_game *game)
{
	int	x;
	int	y;

	game->is_exit = 0;
	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
				game->is_exit++;
			}
			x++;
		}
		y++;
	}
}

int	validcheck(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->col || y < 0 || y >= game->row)
		return (1);
	if (game->valid[y][x] == 1)
		return (1);
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

void	invalid_path_check(t_game *game, int x, int y)
{
	if (validcheck(game, x, y))
		return ;
	game->valid[y][x] = 1;
	if (game->map[y][x] == 'C')
		game->is_coin++;
	if (game->map[y][x] == 'E')
		game->is_exit++;
	invalid_path_check(game, x + 1, y);
	invalid_path_check(game, x - 1, y);
	invalid_path_check(game, x, y + 1);
	invalid_path_check(game, x, y - 1);
}
