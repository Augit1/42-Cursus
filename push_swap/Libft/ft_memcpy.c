/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:52:58 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/10 18:53:12 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (dst);
}
