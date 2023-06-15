/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:58 by arashido          #+#    #+#             */
/*   Updated: 2023/06/15 14:23:14 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// this function checks the border top and bottom
int	check_line_horizontal(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// this function checks the border right and left
int	check_line_vertical(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = ft_strlen(line);
	while (line[i])
	{
		if (line[0] != '1')
			return (0);
		else if (i + 1 == count)
		{
			if (line[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

// this function counts the line of the map
int	get_row(char *str)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

// this function checks all the borders
int	check_border(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = get_row_count(map);
	while (map[i])
	{
		if (i == 0)
		{
			if (check_line_horizontal(map[i]) == 0)
				return (0);
		}
		else if (i == count - 1)
		{
			if (check_line_horizontal(map[i]) == 0)
				return (0);
		}
		else
		{
			if (check_line_vertical(map[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
