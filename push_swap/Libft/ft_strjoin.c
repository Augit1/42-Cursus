/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:57 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/11 18:54:09 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	int		totallen;
	int		i;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	catstr = malloc((totallen + 1) * sizeof(char));
	i = 0;
	if (!catstr)
		return (NULL);
	while (s1[i] && totallen-- > 0)
	{
		catstr[i] = s1[i];
		i++;
	}
	while (*s2 && totallen-- > 0)
	{
		catstr[i] = *s2;
		s2++;
		i++;
	}
	catstr[i] = '\0';
	return (catstr);
}
