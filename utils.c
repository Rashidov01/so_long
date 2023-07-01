/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:30:26 by arashido          #+#    #+#             */
/*   Updated: 2023/07/01 17:07:39 by arashido         ###   ########.fr       */
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

void	ft_free_arr(char **p)
{
	int	i;

	i = 0;
	while (p != NULL && p[i])
	{
		free(p[i]);
		i++;
	}
	if (p)
	{
		free(p);
		p = NULL;
	}
}

int	str_compare_fn(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->map);
	exit(0);
}

int	count_collactable(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += check_line(map[i], 'C');
		i++;
	}
	if (count == 0)
		return (0);
	return (count);
}
