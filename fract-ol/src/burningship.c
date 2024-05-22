/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:37:51 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 16:10:19 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burningship(t_data *f)
{
	int	px;
	int	py;

	px = -1;
	while (++px < LARGEUR)
	{
		py = -1;
		while (++py < HAUTEUR)
		{
			f->x0 = f->movex - 2.5 / f->zoom + (px * 3.5 / LARGEUR) / f->zoom;
			f->y0 = f->movey - 1.5 / f->zoom + (py * 3.0 / HAUTEUR) / f->zoom;
			f->x = 0.0;
			f->y = 0.0;
			f->iteration = 0;
			while (f->x * f->x + f->y * f->y <= 4 && f->iteration < f->max_iter)
			{
				f->xtemp = f->x * f->x - f->y * f->y + f->x0;
				f->y = ft_fabs(2 * f->x * f->y) + f->y0;
				f->x = f->xtemp;
				f->iteration++;
			}
			iterate_color(f, px, py);
		}
	}
}
