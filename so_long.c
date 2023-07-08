/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:56:01 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:43:33 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *str)
{
	t_game	game;

	game.row = get_row(str);
	game.map = malloc(sizeof(char *) * (game.row + 1));
	game.j = 0;
	while (game.j < game.row + 1)
		game.map[game.j++] = NULL;
	game.fd = open(str, O_RDONLY);
	game.i = 0;
	game.line = get_next_line(game.fd);
	while (game.line)
	{
		if (str_compare_fn("\n", game.line) == 0)
			return (ft_free_arr(game.map), free(game.line), NULL);
		game.arr = ft_split(game.line, '\n');
		game.map[game.i] = game.arr[0];
		free(game.arr);
		free(game.line);
		game.line = get_next_line(game.fd);
		game.i++;
	}
	game.map[game.i] = NULL;
	close(game.fd);
	return (game.map);
}

void	close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->map);
	exit(0);
}

int	mouse_event(t_game *game)
{
	close_window(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(1, "less parameter\n", 16);
		return (1);
	}
	if (ft_map_parsing(av) == 1)
		return (1);
	game.map = get_map(av[1]);
	game.row = get_row_count(game.map);
	game.col = ft_strlen(game.map[0]);
	game.mlx = mlx_init();
	mainchecker(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.col * 64, game.row * 64,
			"so_long");
	game.coins = count_collactable(game.map);
	draw_map(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, mouse_event, &game);
	mlx_loop(game.mlx);
	free(game.map);
	ft_free_arr(game.arr);
	return (0);
}
