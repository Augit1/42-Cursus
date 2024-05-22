/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:29:38 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/10 20:54:45 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_data *f)
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
			f->x = f->x0;
			f->y = f->y0;
			f->iteration = 0;
			while (f->x * f->x + f->y * f->y <= 4 && f->iteration < f->max_iter)
			{
				f->xtemp = f->x * f->x - f->y * f->y + f->cx;
				f->y = 2 * f->x * f->y + f->cy;
				f->x = f->xtemp;
				f->iteration++;
			}
			iterate_color(f, px, py);
		}
	}
}
