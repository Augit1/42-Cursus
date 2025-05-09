/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_maths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:01:48 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 16:21:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "initialisation.h"

void	calculate_ray(int x, t_data *data, t_cast *cast)
{
	double	screen_width;
	double	pos_x;
	double	pos_y;

	screen_width = (double)data->win_width;
	pos_x = data->player_x;
	pos_y = data->player_y;
	cast->camera_x = 2.0 * x / screen_width - 1.0;
	cast->ray_dir_x = cast->dir_x + cast->plane_x * cast->camera_x;
	cast->ray_dir_y = cast->dir_y + cast->plane_y * cast->camera_x;
	cast->map_x = (int)pos_x;
	cast->map_y = (int)pos_y;
	if (cast->ray_dir_x == 0)
		cast->delta_dist_x = 1e30;
	else
		cast->delta_dist_x = fabs(1.0 / cast->ray_dir_x);
	if (cast->ray_dir_y == 0)
		cast->delta_dist_y = 1e30;
	else
		cast->delta_dist_y = fabs(1.0 / cast->ray_dir_y);
}

void	calculate_step_and_side_dist(t_data *data, t_cast *cast)
{
	double	pos_x;
	double	pos_y;

	pos_x = data->player_x;
	pos_y = data->player_y;
	if (cast->ray_dir_x < 0)
	{
		cast->step_x = -1;
		cast->side_dist_x = (pos_x - cast->map_x) * cast->delta_dist_x;
	}
	else
	{
		cast->step_x = 1;
		cast->side_dist_x = (cast->map_x + 1.0 - pos_x) * cast->delta_dist_x;
	}
	if (cast->ray_dir_y < 0)
	{
		cast->step_y = -1;
		cast->side_dist_y = (pos_y - cast->map_y) * cast->delta_dist_y;
	}
	else
	{
		cast->step_y = 1;
		cast->side_dist_y = (cast->map_y + 1.0 - pos_y) * cast->delta_dist_y;
	}
}

void	calculate_wall_distance(t_data *data, t_cast *cast)
{
	double	pos_x;
	double	pos_y;

	pos_x = data->player_x;
	pos_y = data->player_y;
	if (cast->side == 0)
		cast->perp_wall_dist = (cast->map_x - pos_x
				+ (1 - cast->step_x) / 2.0) / cast->ray_dir_x;
	else
		cast->perp_wall_dist = (cast->map_y - pos_y
				+ (1 - cast->step_y) / 2.0) / cast->ray_dir_y;
}

void	calculate_line_height(t_data *data, t_cast *cast)
{
	int	screen_height;

	screen_height = data->win_height;
	cast->line_height = (int)(screen_height / cast->perp_wall_dist);
	cast->draw_start = -cast->line_height / 2 + screen_height / 2;
	if (cast->draw_start < 0)
		cast->draw_start = 0;
	cast->draw_end = cast->line_height / 2 + screen_height / 2;
	if (cast->draw_end >= screen_height)
		cast->draw_end = screen_height - 1;
}

void	calculate_texture_coordinates(t_data *data, t_cast *cast)
{
	double	wall_x;
	double	pos_x;
	double	pos_y;

	pos_x = data->player_x;
	pos_y = data->player_y;
	if (cast->side == 0)
		wall_x = pos_y + cast->perp_wall_dist * cast->ray_dir_y;
	else
		wall_x = pos_x + cast->perp_wall_dist * cast->ray_dir_x;
	wall_x -= floor(wall_x);
	cast->tex_x = (int)(wall_x * cast->tex_width);
	if (cast->side == 0 && cast->ray_dir_x > 0)
		cast->tex_x = cast->tex_width - cast->tex_x - 1;
	if (cast->side == 1 && cast->ray_dir_y < 0)
		cast->tex_x = cast->tex_width - cast->tex_x - 1;
}
