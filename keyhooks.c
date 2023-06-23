/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:48:35 by arashido          #+#    #+#             */
/*   Updated: 2023/06/23 18:06:06 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_exit(t_game *game, int x, int y)
{
	if (game->markexit == 1 && game->map[y][x] != 'E')
	{
		graphics(game, EXIT, game->position_x, game->position_y);
		game->markexit = 0;
	}
}

void	movescount(t_game *game, int x, int y, int flag)
{
	if (flag == 1)
		printf("Moves: %d\n", game->moves++);
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->coins--;
	}
	game->position_x = x;
	game->position_y = y;
}

void	win(t_game *game)
{
	if (game->coins <= 0
		&& game->map[game->position_y][game->position_x] == 'E')
	{
		printf("\n\nYOU WIN !!!\n\n");
		close_window(game);
	}
}

int	moves(t_game *game, int x, int y)
{
	if (game->map[game->position_y + y][game->position_x + x] == '1')
		return (0);
	else if (game->map[game->position_y + y][game->position_x + x] == 'E'
			&& game->coins > 0)
	{
		graphics(game, SPACE, game->position_x, game->position_y);
		graphics(game, ME, game->position_x, game->position_y);
		graphics(game, EXIT, game->position_x + (x), game->position_y + (y));
	}
	else
	{
		graphics(game, SPACE, game->position_x, game->position_y);
		graphics(game, ME, game->position_x + x, game->position_y + y);
		movescount(game, game->position_x + x, game->position_y + y, 1);
		win(game);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13) //w
		moves(game, 0, -1);
	else if (keycode == 0) //a
		moves(game, -1, 0);
	else if (keycode == 1) //s
		moves(game, 0, 1);
	else if (keycode == 2) //d
		moves(game, 1, 0);
	else if (keycode == 53)
		close_window(game);
	return (0);
}