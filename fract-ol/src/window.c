/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:39:19 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 16:45:16 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *f, int px, int py)
{
	char	*dst;

	dst = f->addr + (py * f->line_length + px * (f->bpp / 8));
	*(unsigned int *)dst = f->color;
}

int	close_window(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	free(img->mlx);
	exit(0);
	return (0);
}

void	draw(t_data *img)
{
	img->draw_fractal(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	display_values(img, LARGEUR, HAUTEUR);
}

static void	display_fractal(t_data *img, int xp, int yp)
{
	char	*cx_s;
	char	*cy_s;

	if (img->fractal == MANDELBROT)
		mlx_string_put(img->mlx, img->win, xp, yp, 0xFFFFFF, img->name);
	else if (img->fractal == BURNINGSHIP)
		mlx_string_put(img->mlx, img->win, xp, yp, 0xFFFFFF, img->name);
	else if (img->fractal == JULIA)
	{
		yp -= 30;
		cx_s = ft_itoa_double(img->cx);
		cy_s = ft_itoa_double(img->cy);
		mlx_string_put(img->mlx, img->win, xp, yp, 0xFFFFFF, img->name);
		mlx_string_put(img->mlx, img->win, xp, yp + 20, 0xFFFFFF, "cx: ");
		mlx_string_put(img->mlx, img->win, xp + 50, yp + 20, 0xFFFFFF, cx_s);
		mlx_string_put(img->mlx, img->win, xp, yp + 35, 0xFFFFFF, "cy: ");
		mlx_string_put(img->mlx, img->win, xp + 50, yp + 35, 0xFFFFFF, cy_s);
		free(cx_s);
		free(cy_s);
	}
}

void	display_values(t_data *img, int xp, int yp)
{
	char	*maxiter_s;
	char	*zoom_s;
	char	*movex_s;
	char	*movey_s;

	xp -= 100;
	yp -= 70;
	maxiter_s = ft_itoa_double(img->max_iter);
	zoom_s = ft_itoa_double(img->zoom);
	movex_s = ft_itoa_double(img->movex);
	movey_s = ft_itoa_double(img->movey);
	display_fractal(img, xp, yp);
	mlx_string_put(img->mlx, img->win, xp, yp + 20, 0xFFFFFF, "zoom: ");
	mlx_string_put(img->mlx, img->win, xp + 50, yp + 20, 0xFFFFFF, zoom_s);
	mlx_string_put(img->mlx, img->win, xp, yp + 35, 0xFFFFFF, "moveX: ");
	mlx_string_put(img->mlx, img->win, xp + 50, yp + 35, 0xFFFFFF, movex_s);
	mlx_string_put(img->mlx, img->win, xp, yp + 50, 0xFFFFFF, "moveY: ");
	mlx_string_put(img->mlx, img->win, xp + 50, yp + 50, 0xFFFFFF, movey_s);
	mlx_string_put(img->mlx, img->win, xp, yp + 65, 0xFFFFFF, "iter max: ");
	mlx_string_put(img->mlx, img->win, xp + 70, yp + 65, 0xFFFFFF, maxiter_s);
	free(zoom_s);
	free(movex_s);
	free(movey_s);
	free(maxiter_s);
}
