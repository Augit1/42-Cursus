/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:50:26 by aude-la-          #+#    #+#             */
/*   Updated: 2024/09/18 16:37:27 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = (unsigned char) c;
		p++;
		len--;
	}
	return (b);
}
/*
#include <stdio.h>
int main()
{
	void *ptr;
	int i;

	ptr = malloc(10);
	ptr = ft_memset(ptr, 9, 8);
	i = 0;
	while (i < 10)
	{
		printf("%d", ((unsigned char *)ptr)[i]);
		i++;
	}
}
*/
