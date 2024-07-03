/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:27:17 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/31 18:52:54 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

int	ft_isnumber(char *s)
{
	int	i;
	int	digit;

	digit = 0;
	i = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		digit = 1;
		i++;
	}
	if (!digit)
		return (0);
	if (s[i] && (s[i] == '.' || s[i] == ','))
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	return (s[i] == '\0');
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	check;

	check = 0;
	if (argc < 5 || argc > 6)
		check = 1;
	i = 0;
	while (++i < 5 && (check == 0))
		if (!ft_isnumber(argv[i]))
			check = 1;
	if (argc == 6 && (check == 0))
		if (!ft_isnumber(argv[i]))
			check = 1;
	if (check != 0)
	{
		printf("\nYou need to precise the following arguments :\n");
		printf("\t- number of philosophers\n");
		printf("\t- time to die\n");
		printf("\t- time to eat\n");
		printf("\t- time to sleep\n");
		printf("\t- number of times each philosopher must eat (optional)\n\n");
		return (1);
	}
	return (0);
}
