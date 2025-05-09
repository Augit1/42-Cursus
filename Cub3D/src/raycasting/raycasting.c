/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:43:52 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 17:42:37 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "initialisation.h"

void	initialize_image(t_data *data, t_cast *cast)
{
	int	screen_width;
	int	screen_height;

	screen_width = data->win_width;
	screen_height = data->win_height;
	cast->image = mlx_new_image(data->mlx, screen_width, screen_height);
	if (!cast->image)
		return ;
	cast->img_addr = mlx_get_data_addr(cast->image,
			&cast->img_bits_per_pixel,
			&cast->img_size_line,
			&cast->img_endian);
	if (!cast->img_addr)
	{
		mlx_destroy_image(data->mlx, cast->image);
		return ;
	}
}

void	draw_raycast(t_data *data)
{
	t_cast	*cast;
	int		screen_width;
	int		x;

	cast = data->cast;
	screen_width = data->win_width;
	initialize_image(data, cast);
	draw_colors(data);
	x = 0;
	while (x < screen_width)
	{
		calculate_ray(x, data, cast);
		calculate_step_and_side_dist(data, cast);
		perform_dda(data, cast);
		calculate_wall_distance(data, cast);
		calculate_line_height(data, cast);
		calculate_texture_coordinates(data, cast);
		draw_vertical_line(x, data, cast);
		x++;
	}
	display_image(data, cast);
}
