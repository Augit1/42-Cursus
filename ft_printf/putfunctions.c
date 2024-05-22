/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:34:12 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/07 16:03:52 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "putfunctions.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	length;

	length = 0;
	if (!str)
		length = 0;
	else
	{
		while (str[length])
			length++;
	}
	return (write(1, str, length));
}

int	ft_putnbr(int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count < 0)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		if (count < 0)
			return (-1);
	}
	count += ft_putchar((n % 10) + '0');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putunbr(nb / 10);
		if (count < 0)
			return (-1);
	}
	count += ft_putchar((nb % 10) + '0');
	if (count < 0)
		return (-1);
	return (count);
}
