/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:11:44 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/23 11:12:16 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static char	*ft_allocstr(int len)
{
	char	*num_str;

	num_str = NULL;
	num_str = malloc((len + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	return (num_str);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		value;
	int		len;

	value = n;
	len = 1;
	while (value > 9)
	{
		value /= 10;
		len++;
	}
	number = ft_allocstr(len);
	if (!number)
		return (NULL);
	number[len] = '\0';
	value = n;
	while (len--)
	{
		number[len] = (value % 10) + '0';
		value /= 10;
	}
	return (number);
}

int	is_all_zeroes(const char *str)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
