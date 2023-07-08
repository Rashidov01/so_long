/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:03:27 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:39:17 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validchecker(t_game *game)
{
	int	reachable_coins;

	find_exit(game);
	find_player(game);
	invalid_path_check(game, game->position_x, game->position_y);
	if (!game->valid[game->exit_y][game->exit_x])
	{
		write(2, "Error: Invalid map - Exit is not reachable\n", 43);
		exit(1);
	}
	reachable_coins = count_collactable(game->map);
	if (reachable_coins != game->is_coin)
	{
		write(2, "Error: Invalid map - Not all coins are reachable\n", 48);
		exit(1);
	}
}

int	map_parsing_helper(char **map)
{
	if (map == NULL || check_exit(map) == 0 || check_collectible(map) == 0
		|| check_start(map) == 0 || check_border(map) == 0
		|| check_extra_character(map) == 0 || check_map_rectangle(map) == 0)
	{
		if (map == NULL)
			write(2, "Error: Invalide map !!!\n", 25);
		return (1);
	}
	return (0);
}

int	ft_map_parsing(char **av)
{
	char	**map;

	map = NULL;
	if (file_check(av[1]) == 0 || file_check_permission(av[1]) == 0)
	{
		write(2, "file format error\n", 19);
		return (1);
	}
	map = get_map(av[1]);
	if (map_parsing_helper(map) == 1)
	{
		ft_free_arr(map);
		return (1);
	}
	ft_free_arr(map);
	return (0);
}

void	mainchecker(t_game *game)
{
	game->is_coin = 0;
	game->coins = 0;
	game->is_exit = 0;
	game->exit_map = 0;
	validchecker(game);
	hashmaker(game);
}
