/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:14:50 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/10 14:53:49 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_cx_cy_values(t_anim *a)
{
	a->cx_values[0] = -0.7;
	a->cy_values[0] = 0.27015;
	a->cx_values[1] = -0.7269;
	a->cy_values[1] = 0.1889;
	a->cx_values[2] = 0.355;
	a->cy_values[2] = 0.355;
	a->cx_values[3] = 0.285;
	a->cy_values[3] = 0.01;
	a->cx_values[4] = -0.835;
	a->cy_values[4] = -0.2321;
	a->cx_values[5] = -0.8;
	a->cy_values[5] = 0.156;
	a->cx_values[6] = -0.75;
	a->cy_values[6] = 0.11;
	a->cx_values[7] = -0.70176;
	a->cy_values[7] = -0.3842;
	a->cx_values[8] = -0.74543;
	a->cy_values[8] = 0.11301;
	a->cx_values[9] = -0.70176;
	a->cy_values[9] = 0.46557;
}

static double	interpolate(double start, double end, double t)
{
	return (start * (1.0 - t) + end * t);
}

void	animate(t_data *img, int sens)
{
	static t_anim	a = {0, 100, 0, 0.0, {0}, {0}};
	static int		direction = 1;
	int				index;

	if (!a.exist)
	{
		init_cx_cy_values(&a);
		a.exist = 1;
	}
	if (!sens)
		direction = -1;
	else
		direction = 1;
	index = (a.i + direction) % 10;
	if (index < 0)
		index = -index;
	a.t = (double)a.i / a.steps;
	img->cx = interpolate(a.cx_values[index], a.cx_values[a.i], a.t);
	img->cy = interpolate(a.cy_values[index], a.cy_values[a.i], a.t);
	draw(img);
	a.i = (a.i + direction) % 10;
	if (a.i < 0)
		a.i = 9;
}
