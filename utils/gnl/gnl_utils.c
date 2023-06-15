/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:55:50 by arashido          #+#    #+#             */
/*   Updated: 2023/05/28 15:12:32 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substring;
	int		i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substring = malloc(sizeof(char) * len + 1);
	if (!substring)
		return (0);
	while (start < ft_strlen(s) && s[start] && i < len)
	{
		substring[i++] = s[start++];
	}
	substring[i] = '\0';
	return (substring);
}

static int	wordcounter(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c)
		j++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char *s, char c)
{
	char	**retres;
	int		wd;
	int		i;
	int		j;

	wd = wordcounter(s, c);
	retres = malloc((wd + 1) * 8);
	if (!retres)
		return (NULL);
	i = 0;
	wd = 0;
	while (s[i] != '\0' && wd < wordcounter(s, c))
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		retres[wd++] = ft_substr(&s[i], 0, j);
		i = i + j;
	}
	retres[wd] = 0;
	return (retres);
}
