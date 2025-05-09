/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:10:47 by aude-la-          #+#    #+#             */
/*   Updated: 2024/07/11 16:57:30 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchar(const char *s, char c)
{
	int	result;

	result = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			result++;
		while (*s && *s != c)
			s++;
	}
	return (result);
}

static char	**ft_filltab(const char *s, char **tab, char c, int index)
{
	int		i;
	int		start;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[index] = ft_substr(s, start, i - start);
			if (!tab[index])
			{
				while (index >= 0)
					free(tab[index--]);
				return (NULL);
			}
			index++;
		}
		else
			i++;
	}
	tab[index] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**tab;

	index = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_countchar(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_filltab(s, tab, c, index))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
