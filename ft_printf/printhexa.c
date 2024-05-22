/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:38:49 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/07 16:07:10 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printhexa.h"
#include "putfunctions.h"

int	ft_printhexa_ptr(va_list *args)
{
	unsigned long	ptr_hexa;
	int				count;

	count = 0;
	ptr_hexa = (unsigned long) va_arg(*args, void *);
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	count += ft_puthexa(ptr_hexa);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_printhexa(va_list *args, char up)
{
	unsigned long	nb_hexa;

	nb_hexa = (unsigned long) va_arg(*args, long);
	if (up == 1)
		return (ft_puthexa_up((unsigned int) nb_hexa));
	return (ft_puthexa((unsigned int) nb_hexa));
}

int	ft_puthexa(unsigned long num_hexa)
{
	char	*hexdigits;
	int		count;

	count = 0;
	hexdigits = "0123456789abcdef";
	if (num_hexa >= 16)
	{
		count += ft_puthexa(num_hexa / 16);
		if (count < 0)
			return (-1);
	}
	count += ft_putchar(hexdigits[num_hexa % 16]);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_puthexa_up(unsigned long num_hexa)
{
	char	*hexdigits;
	int		count;

	count = 0;
	hexdigits = "0123456789ABCDEF";
	if (num_hexa >= 16)
	{
		count += ft_puthexa_up(num_hexa / 16);
		if (count < 0)
			return (-1);
	}
	count += ft_putchar(hexdigits[num_hexa % 16]);
	if (count < 0)
		return (-1);
	return (count);
}
