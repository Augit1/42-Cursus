/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:27:18 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 18:42:25 by augustindelab    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialisation.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(init_errors(MLX, NULL));
}

void	display_values(t_data *data)
{
	int		xp;
	int		yp;
	char	*rot;
	char	*mov;

	xp = WIDTH - 120;
	yp = HEIGHT - 50;
	mov = ft_itoa_double(data->rot_speed);
	rot = ft_itoa_double(data->move_speed);
	mlx_string_put(data->mlx, data->win, xp + 40, yp, 0xFFFFFF, "CUB3D");
	mlx_string_put(data->mlx, data->win, xp, yp + 35, 0xFFFFFF, "mov speed: ");
	mlx_string_put(data->mlx, data->win, xp + 80, yp + 20, 0xFFFFFF, mov);
	mlx_string_put(data->mlx, data->win, xp, yp + 20, 0xFFFFFF, "rot speed: ");
	mlx_string_put(data->mlx, data->win, xp + 80, yp + 35, 0xFFFFFF, rot);
	free(mov);
	free(rot);
}

void	display_image(t_data *data, t_cast *cast)
{
	mlx_put_image_to_window(data->mlx, data->win, cast->image, 0, 0);
	display_values(data);
	mlx_destroy_image(data->mlx, cast->image);
}

void	init_display(t_config *config)
{
	t_data	data;

	data.config = config;
	init_mlx(&data);
	create_window(&data);
	init_game(&data, config);
	load_textures(&data);
	get_texture_addr(&data);
	draw_raycast(&data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
