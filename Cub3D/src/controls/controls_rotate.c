/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:25:28 by aude-la-          #+#    #+#             */
/*   Updated: 2025/02/13 17:56:47 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

void	rotate_right(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->cast->dir_x;
	data->cast->dir_x = data->cast->dir_x * cos(rot_speed)
		- data->cast->dir_y * sin(rot_speed);
	data->cast->dir_y = old_dir_x * sin(rot_speed)
		+ data->cast->dir_y * cos(rot_speed);
	old_plane_x = data->cast->plane_x;
	data->cast->plane_x = data->cast->plane_x * cos(rot_speed)
		- data->cast->plane_y * sin(rot_speed);
	data->cast->plane_y = old_plane_x * sin(rot_speed)
		+ data->cast->plane_y * cos(rot_speed);
}

void	rotate_left(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->cast->dir_x;
	data->cast->dir_x = data->cast->dir_x * cos(-rot_speed)
		- data->cast->dir_y * sin(-rot_speed);
	data->cast->dir_y = old_dir_x * sin(-rot_speed)
		+ data->cast->dir_y * cos(-rot_speed);
	old_plane_x = data->cast->plane_x;
	data->cast->plane_x = data->cast->plane_x * cos(-rot_speed)
		- data->cast->plane_y * sin(-rot_speed);
	data->cast->plane_y = old_plane_x * sin(-rot_speed)
		+ data->cast->plane_y * cos(-rot_speed);
}
