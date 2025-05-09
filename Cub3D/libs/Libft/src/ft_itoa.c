/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:59:36 by aude-la-          #+#    #+#             */
/*   Updated: 2024/07/15 20:42:08 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizenum(int n)
{
	int	len_num;

	len_num = 1;
	if (n < 0)
	{
		len_num++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len_num++;
	}
	return (len_num);
}

static char	*ft_allocstr(int len)
{
	char	*num_str;

	num_str = malloc(len + 1);
	if (!num_str)
		return (NULL);
	return (num_str);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		value;
	int		len;

	len = ft_sizenum(n);
	number = ft_allocstr(len);
	if (!number)
		return (NULL);
	number[len] = '\0';
	value = n;
	if (n < 0)
		value = -value;
	while (len-- && (value > 0))
	{
		number[len] = (value % 10) + '0';
		value /= 10;
	}
	if (n < 0)
		*number = '-';
	else if (n == 0)
		*number = '0';
	return (number);
}
