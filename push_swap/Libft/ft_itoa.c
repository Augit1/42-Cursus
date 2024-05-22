/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:59:36 by aude-la-          #+#    #+#             */
/*   Updated: 2024/01/18 14:32:41 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;
	int		value;
	int		len;

	len = ft_sizenum(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = ft_allocstr(len);
	if (!number)
		return (NULL);
	number[len] = '\0';
	value = n;
	if (n < 0)
		value = -n;
	while (len--)
	{
		number[len] = (value % 10) + '0';
		value /= 10;
	}
	if (n < 0)
		*number = '-';
	return (number);
}

int	ft_sizenum(int n)
{
	int	len_num;

	len_num = 1;
	if (n < 0)
		len_num++;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		len_num++;
	}
	return (len_num);
}

char	*ft_allocstr(int len)
{
	char	*num_str;

	num_str = NULL;
	num_str = malloc((len + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	return (num_str);
}
