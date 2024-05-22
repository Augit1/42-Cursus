/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:51:36 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/17 12:39:27 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	if ((ptr_dst <= ptr_src) || (ptr_dst >= ptr_src + len))
		return (ft_memcpy(ptr_dst, ptr_src, len));
	else
	{
		ptr_dst += len;
		ptr_src += len;
		while (len-- > 0)
			*(--ptr_dst) = *(--ptr_src);
	}
	return (dst);
}
