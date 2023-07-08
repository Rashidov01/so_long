/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:58:05 by arashido          #+#    #+#             */
/*   Updated: 2023/07/03 14:53:49 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		substr_length;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else
	{
		substr_length = ft_strlen(&s[start]);
		if (len > substr_length)
			len = substr_length;
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		start;
	int		end;
	int		i;

	if (!(s))
		return (0);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!(split))
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	split[i] = 0;
	return (split);
}
