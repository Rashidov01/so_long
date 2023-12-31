/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:56 by arashido          #+#    #+#             */
/*   Updated: 2023/07/05 16:56:22 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i > 4 && str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (1);
	return (0);
}

int	file_check_permission(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

int	get_row_count(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_map_rectangle(char **map)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(map[i]);
	while (map[i] && i < get_row_count(map) - 1)
	{
		i++;
		if (length != ft_strlen(map[i]))
			return (write(2, "Error: Map is not rectangle!!!\n", 32), 0);
	}
	return (1);
}

int	check_start(char **map)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += check_line(map[i], 'P');
		i++;
	}
	if (count != 1)
		return (write(2, "Error: There is no Player or more\n", 35), 0);
	return (1);
}
