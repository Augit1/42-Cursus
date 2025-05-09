/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:59:57 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:03 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "initialisation.h"

char	*select_wall_texture(t_cast *cast)
{
	if (cast->side == 0)
	{
		if (cast->ray_dir_x > 0)
			return (cast->eastwall_addr + (cast->tex_y
					* cast->eastwall_size_line + cast->tex_x
					* (cast->eastwall_bits_per_pixel / 8)));
		else
			return (cast->westwall_addr + (cast->tex_y
					* cast->westwall_size_line + cast->tex_x
					* (cast->westwall_bits_per_pixel / 8)));
	}
	else
	{
		if (cast->ray_dir_y > 0)
			return (cast->southwall_addr + (cast->tex_y
					* cast->southwall_size_line + cast->tex_x
					* (cast->southwall_bits_per_pixel / 8)));
		else
			return (cast->northwall_addr + (cast->tex_y
					* cast->northwall_size_line + cast->tex_x
					* (cast->northwall_bits_per_pixel / 8)));
	}
	return (NULL);
}

void	draw_colors(t_data *data)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			pixel = data->cast->img_addr + (y * data->cast->img_size_line
					+ x * (data->cast->img_bits_per_pixel / 8));
			if (y < data->win_height / 2)
				*(int *)pixel = data->config->ceiling_color;
			else
				*(int *)pixel = data->config->floor_color;
			x++;
		}
		y++;
	}
}

void	draw_vertical_line(int x, t_data *data, t_cast *cast)
{
	int		y;
	int		d;
	int		color;
	char	*pixel_addr;
	char	*img_pixel;

	y = cast->draw_start;
	while (y < cast->draw_end)
	{
		d = y * 256 - data->win_height * 128 + cast->line_height * 128;
		cast->tex_y = ((d * cast->tex_height) / cast->line_height) / 256;
		if (cast->tex_y < 0)
			cast->tex_y = 0;
		else if (cast->tex_y >= cast->tex_height)
			cast->tex_y = cast->tex_height - 1;
		pixel_addr = select_wall_texture(cast);
		color = *(int *)pixel_addr;
		img_pixel = cast->img_addr + (y * cast->img_size_line
				+ x * (cast->img_bits_per_pixel / 8));
		*(int *)img_pixel = color;
		y++;
	}
}

void	perform_dda(t_data *data, t_cast *cast)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cast->side_dist_x < cast->side_dist_y)
		{
			cast->side_dist_x += cast->delta_dist_x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist_y += cast->delta_dist_y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}
		if (cast->map_x < 0 || cast->map_x >= data->config->map_width
			|| cast->map_y < 0 || cast->map_y >= data->config->map_height)
			hit = 1;
		else if (data->map[cast->map_y][cast->map_x] == '1')
			hit = 1;
	}
	cast->hit = hit;
}
