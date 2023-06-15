/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:30:34 by arashido          #+#    #+#             */
/*   Updated: 2023/06/03 19:42:32 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_character(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'E' && str[i] != 'P' && str[i] != 'C' && str[i] != '1'
			&& str[i] != '0' && str[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_extra_character(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_character(map[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_exit(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += check_line(map[i], 'E');
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_collectible(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += check_line(map[i], 'C');
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
}
