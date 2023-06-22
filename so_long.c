/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:56:01 by arashido          #+#    #+#             */
/*   Updated: 2023/06/23 02:08:27 by arashido         ###   ########.fr       */
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
		if (str_compare("\n", game.line) == 0)
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

int	map_parsing_helper(char **map)
{
	if (map == NULL || check_exit(map) == 0 || check_collectible(map) == 0
		|| check_start(map) == 0 || check_border(map) == 0
		|| check_extra_character(map) == 0 || check_map_rectangle(map) == 0)
	{
		write(2, "In the map has ERROR !!!\n", 26);
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
	game.mlx_win = mlx_new_window(game.mlx, game.col * 64, game.row * 64,
			"so_long");
	game.coins = count_collactable(game.map);
	printf("%d\n", game.coins);
	draw_map(&game);
	// mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, mouse_event, &game);
	mlx_loop(game.mlx);
	free(game.map);
	ft_free_arr(game.arr);
	return (0);
}
