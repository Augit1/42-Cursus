/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:36:18 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/10 20:55:27 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_data *f)
{
	int	px;
	int	py;

	px = -1;
	while (++px < LARGEUR)
	{
		py = -1;
		while (++py < HAUTEUR)
		{
			f->x0 = f->movex - 0.5 / f->zoom + (px * 1.0 / LARGEUR) / f->zoom;
			f->y0 = f->movey - 0.5 / f->zoom + (py * 1.0 / HAUTEUR) / f->zoom;
			f->x = 0.0;
			f->y = 0.0;
			f->iteration = 0;
			while (f->x * f->x + f->y * f->y <= 4 && f->iteration < f->max_iter)
			{
				f->xtemp = f->x * f->x - f->y * f->y + f->x0;
				f->y = 2 * f->x * f->y + f->y0;
				f->x = f->xtemp;
				f->iteration++;
			}
			iterate_color(f, px, py);
		}
	}
}
