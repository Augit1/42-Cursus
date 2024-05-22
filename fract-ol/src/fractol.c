/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:27 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 21:11:01 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;

	if (((argc != 2) && (argc != 4)) || (argv[1][1]))
		clean_exit();
	args_init(argc, argv, &img);
	init(&img);
	draw(&img);
	mlx_hook(img.win, 2, 3, key_hook, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
