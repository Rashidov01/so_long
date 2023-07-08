/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:30:26 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:42:20 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_and_exit(t_game *game)
{
	ft_free_arr(game->map);
	free(game->map);
	exit(1);
}

void	hashmaker(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->size_y)
	{
		x = 0;
		while (x < game->size_x)
		{
			game->valid[y][x] = 0;
			x++;
		}
		y++;
	}
}
