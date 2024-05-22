/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:49:09 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/10 17:07:03 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;

	ptr_s = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*ptr_s == (unsigned char) c)
			return ((void *) ptr_s);
		ptr_s++;
	}
	return (NULL);
}
