/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:04:07 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/10 17:08:22 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*cpy;

	size = 0;
	cpy = NULL;
	while (s1[size])
		size++;
	cpy = malloc(size + 1);
	if (cpy)
	{
		cpy = ft_memcpy(cpy, s1, size);
		cpy[size] = '\0';
	}
	return (cpy);
}
