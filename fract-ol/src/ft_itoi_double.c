/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:25:07 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/10 19:30:00 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_sizenum(double n)
{
	int	len_num;

	len_num = 1;
	if (n < 0)
	{
		len_num++;
		n = -n;
	}
	if ((int)n * 1000 != (int)(n * 1000))
		len_num += 4;
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

	num_str = malloc((len + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	return (num_str);
}

static void	decimal_part(char *number, double n, int *len)
{
	int	i;

	if (n < 0)
		n = -n;
	if ((int)n == 0)
		number[(*len) - 5] = '0';
	n *= 1000;
	i = 3;
	while (i--)
	{
		number[--(*len)] = ((int)n % 10) + '0';
		n /= 10;
	}
	number[--(*len)] = '.';
}

char	*ft_itoa_double(double n)
{
	char	*number;
	int		value;
	int		len;

	len = ft_sizenum(n);
	number = ft_allocstr(len);
	if (!number)
		return (NULL);
	number[len] = '\0';
	value = (int)n;
	if (n < 0)
		value = -value;
	if ((int)n * 1000 != (int)(n * 1000))
		decimal_part(number, n, &len);
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
