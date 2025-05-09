/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:25:37 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 15:27:01 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_pow(double base, int exponent)
{
	double	result;
	int		i;

	result = 1.0;
	i = -1;
	while (++i < exponent)
		result *= base;
	return (result);
}

static	double	decimal_part(const char *str, double result)
{
	int	decimal;

	decimal = 0;
	str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10.0 + (*str - '0');
		decimal++;
		str++;
	}
	if (decimal > 0)
		result /= ft_pow(10.0, decimal);
	return (result);
}

double	ft_atoi_double(const char *str)
{
	int		sign;
	double	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.' || *str == ',')
		result = decimal_part(str, result);
	return (result * sign);
}
