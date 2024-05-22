/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:11:44 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/21 20:35:15 by aude-la-         ###   ########.fr       */
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

int	ft_sizenum(int n)
{
	int	len_num;

	len_num = 1;
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


void	secure_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) != 0)
	{
		ft_printf("Error check if: ");
		ft_printf("\n\t- The pid: %d is OK", pid);
		ft_printf("\n\t- seveur is UP\n");
		exit(1);
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_all_zeroes(const char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
