/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:48:35 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:43:26 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game, int x, int y)
{
	if (game->exit_map == 1 && game->map[y][x] != 'E')
	{
		graphics(game, EXIT, game->exit_x, game->exit_y);
		game->exit_map = 0;
	}
}

void	movescount(t_game *game, int x, int y, int flag)
{
	if (flag == 1)
		ft_printf("Moves: %d\n", ++game->moves);
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->coins--;
	}
	game->position_x = x;
	game->position_y = y;
}

void	game_win(t_game *game)
{
	if (game->coins <= 0
		&& game->map[game->position_y][game->position_x] == 'E')
	{
		ft_printf("\n\nYOU WIN !!!\n\n");
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
		game_win(game);
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		moves(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		moves(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		moves(game, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		moves(game, 1, 0);
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}
