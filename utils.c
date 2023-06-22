/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:30:26 by arashido          #+#    #+#             */
/*   Updated: 2023/06/23 01:11:33 by arashido         ###   ########.fr       */
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

int	str_compare(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}