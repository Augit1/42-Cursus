/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:20:48 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/07 16:10:01 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printfunctions.h"
#include "printhexa.h"
#include "putfunctions.h"

int	ft_printf(const char *format, ...)
{
	int		total_count;
	int		count;
	va_list	args;

	total_count = 0;
	va_start(args, format);
	while (*format)
	{
		count = 0;
		if (*format == '%')
		{
			format++;
			count = ft_typechr(format, &args);
		}
		else
			count = ft_putchar((char) *format);
		format++;
		if (count < 0)
			return (-1);
		total_count += count;
	}
	va_end(args);
	return (total_count);
}

int	ft_typechr(const char *format, va_list *args)
{
	int	count;

	count = 0;
	if (*format == '%')
		count = ft_putchar('%');
	else if (*format == 'c')
		count = ft_printchar(args);
	else if (*format == 's')
		count = ft_printstr(args);
	else if (*format == 'p')
		count = ft_printhexa_ptr(args);
	else if (*format == 'd' || *format == 'i')
		count = ft_printnbr(args);
	else if (*format == 'u')
		count = ft_printunbr(args);
	else if (*format == 'x')
		count = ft_printhexa(args, 0);
	else if (*format == 'X')
		count = ft_printhexa(args, 1);
	else
		count = ft_putchar('%') + ft_putchar(*format);
	format++;
	return (count);
}
