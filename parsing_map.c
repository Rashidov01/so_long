/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:58 by arashido          #+#    #+#             */
/*   Updated: 2023/07/01 13:19:06 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_x(char *line)
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

int	check_line_y(char *line)
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
			if (check_line_x(map[i]) == 0)
				return (write(2, "Error: Mistake in the border!!!\n", 33), 0);
		}
		else if (i == count - 1)
		{
			if (check_line_y(map[i]) == 0)
				return (write(2, "Error: Mistake in the border!!!\n", 33), 0);
		}
		else
		{
			if (check_line_y(map[i]) == 0)
				return (write(2, "Error: Mistake in the border!!!\n", 33), 0);
		}
		i++;
	}
	return (1);
}
