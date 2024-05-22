/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:25:42 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/17 15:15:27 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	sub = NULL;
	if (!s)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s))
		sub = ft_strdup("");
	else
	{
		if (start + len > (unsigned int) ft_strlen(s))
			len = (unsigned int) ft_strlen(s) - start;
		sub = malloc((len + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		while (len-- > 0)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
