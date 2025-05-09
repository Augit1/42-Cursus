/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:38:06 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 16:48:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "color.h"

int	mouse_hook(int button, int x, int y, t_data *img)
{
	double	zoom_factor;
	double	cx;
	double	cy;

	cx = (x - LARGEUR / 2) / (0.5 * img->zoom * LARGEUR) + img->movex;
	cy = (y - HAUTEUR / 2) / (0.5 * img->zoom * HAUTEUR) + img->movey;
	zoom_factor = 1.1;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, LARGEUR, HAUTEUR);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	if (button == 4)
		img->zoom *= zoom_factor;
	else if (button == 5)
		img->zoom /= (zoom_factor * 1.1);
	img->movex = cx - ((x - LARGEUR / 2.0) / (0.5 * img->zoom * LARGEUR));
	img->movey = cy - ((y - HAUTEUR / 2.0) / (0.5 * img->zoom * HAUTEUR));
	draw(img);
	return (0);
}

static void	key_color(int keycode, t_data *img)
{
	if (keycode == NUM_1)
		vibrant(img->color_set);
	else if (keycode == NUM_2)
		cold(img->color_set);
	else if (keycode == NUM_3)
		warm(img->color_set);
	else if (keycode == NUM_4)
		rainbow(img->color_set);
	else if (keycode == NUM_5)
		pastel(img->color_set);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == LEFT_KEY)
		img->movex -= 0.1 / img->zoom;
	else if (keycode == RIGHT_KEY)
		img->movex += 0.1 / img->zoom;
	else if (keycode == UP_KEY)
		img->movey -= 0.1 / img->zoom;
	else if (keycode == DOWN_KEY)
		img->movey += 0.1 / img->zoom;
	else if (keycode == PLUS_KEY)
		img->max_iter += 5;
	else if (keycode == MINUS_KEY && (img->max_iter > 0))
		img->max_iter -= 5;
	else if (keycode == P_KEY && (img->fractal == JULIA))
		animate(img, 1);
	else if (keycode == O_KEY && (img->fractal == JULIA))
		animate(img, 0);
	else if ((keycode >= NUM_1) && (keycode <= NUM_5))
		key_color(keycode, img);
	draw(img);
	if (keycode == ESC_KEY)
		close_window(img);
	return (0);
}
