/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:43:16 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 17:54:17 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_isdouble(char *s)
{
	int	i;
	int	digit;

	digit = 0;
	i = 0;
	if ((s[i] == '-') || (s[i] == '+'))
		i++;
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

void	iterate_color(t_data *f, int px, int py)
{
	if (f->iteration == f->max_iter)
		f->color = 0x000000;
	else
		f->color = f->color_set[f->iteration % 10];
	my_mlx_pixel_put(f, px, py);
}
