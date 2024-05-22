/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:10:29 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/12 16:08:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	size_t			len;

	start = 0;
	end = ft_strlen(s1);
	if (!set || !s1 || !*s1)
		return (ft_strdup(""));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strrchr(set, s1[end - 1]))
		end--;
	if (start == end)
		return (ft_strdup(""));
	len = end - start;
	return (ft_substr(s1, start, len));
}
