/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:39:57 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/07 16:00:45 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfunctions.h"
#include "putfunctions.h"

int	ft_printchar(va_list *args)
{
	char	c;

	c = (char) va_arg(*args, int);
	return (ft_putchar(c));
}

int	ft_printstr(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	ft_printnbr(va_list *args)
{
	int	nb;

	nb = va_arg(*args, int);
	return (ft_putnbr(nb));
}

int	ft_printunbr(va_list *args)
{
	unsigned int	nb;

	nb = va_arg(*args, unsigned int);
	return (ft_putunbr(nb));
}
