/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:52:08 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 17:42:19 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "color.h"

void	clean_exit(void)
{
	ft_putstr("Precise following arguments :\n");
	ft_putstr("\t\t\t\t1 for MANDELBROT\n");
	ft_putstr("\t\t\t\t2 for JULIA\n");
	ft_putstr("\t\t\t\t3 for BURNINGSHIP\n");
	ft_putstr("\t\t\t\tyou can specify <cx> <cy> for JULIA\n");
	exit(0);
}

void	init(t_data	*img)
{
	img->mlx = mlx_init();
	img->zoom = 0.5;
	img->movex = 0.0;
	img->movey = 0.0;
	pastel(img->color_set);
	if (img->fractal == MANDELBROT)
		img->movex = -0.5;
	else if (img->fractal == JULIA)
		img->zoom = 0.33;
	else if (img->fractal == BURNINGSHIP)
	{
		img->zoom = 1.2;
		img->movex = 0.2;
		img->movey = -0.3;
		warm(img->color_set);
	}
	img->max_iter = MAX_ITER;
	img->win = mlx_new_window(img->mlx, LARGEUR, HAUTEUR, img->name);
	img->img = mlx_new_image(img->mlx, LARGEUR, HAUTEUR);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
}

static void	init_julia(int argc, char **argv, t_data *img)
{
	img->fractal = JULIA;
	img->draw_fractal = draw_julia;
	img->name = "    Julia";
	if ((argc == 4) && ft_isdouble(argv[2]) && ft_isdouble(argv[3]))
	{
		img->cx = ft_atoi_double(argv[2]);
		img->cy = ft_atoi_double(argv[3]);
	}
	else if (argc == 2)
	{
		img->cx = -0.7;
		img->cy = 0.27015;
	}
	else
		clean_exit();
}

void	args_init(int argc, char **argv, t_data *img)
{
	if ((int)(*argv[1] - '0') == 1)
	{
		img->fractal = MANDELBROT;
		img->draw_fractal = draw_mandelbrot;
		img->name = " Mandelbrot";
	}
	else if ((int)(*argv[1] - '0') == 2)
		init_julia(argc, argv, img);
	else if ((int)(*argv[1] - '0') == 3)
	{
		img->fractal = BURNINGSHIP;
		img->draw_fractal = draw_burningship;
		img->name = "Burningship";
	}
	else
		clean_exit();
}
