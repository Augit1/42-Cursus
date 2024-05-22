/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:00:45 by aude-la-          #+#    #+#             */
/*   Updated: 2024/02/22 19:01:15 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!*s || !s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!*s || !s)
		return (NULL);
	while (*s)
	{
		if ((char) c == *s)
			return ((char *) s);
		s++;
	}
	if ((char) c == *s)
		return ((char *) s);
	return (NULL);
}

void	ft_check_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*catstr;
	int		totallen;
	int		i;

	totallen = ft_strlen(*s1) + ft_strlen(s2);
	catstr = malloc((totallen + 1) * sizeof(char));
	if (!catstr)
		ft_check_free(s1);
	if (!catstr)
		return (NULL);
	i = 0;
	while ((*s1)[i] && totallen-- > 0)
	{
		catstr[i] = (*s1)[i];
		i++;
	}
	while (*s2 && totallen-- >= 0)
	{
		catstr[i] = *s2;
		s2++;
		i++;
	}
	catstr[i] = '\0';
	ft_check_free(s1);
	return (catstr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (unsigned char *) dst;
	ptr_src = (unsigned char *) src;
	while (n-- > 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
	}
	*ptr_dst = '\0';
	return (dst);
}
