/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:46:28 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 18:25:13 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialisation.h"

void	init_cast(t_data *data)
{
	data->cast = malloc(sizeof(t_cast));
	if (!data->cast)
	{
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->mlx)
			free(data->mlx);
		exit(init_errors(MALLOC, NULL));
	}
	data->cast->dir_x = 0.0;
	data->cast->dir_y = 0.0;
	data->cast->plane_x = 0.0;
	data->cast->plane_y = 0.0;
	data->cast->northwall_texture = NULL;
	data->cast->southwall_texture = NULL;
	data->cast->eastwall_texture = NULL;
	data->cast->westwall_texture = NULL;
}

void	init_player(t_cast *cast, char orientation)
{
	if (orientation == 'N')
	{
		cast->dir_y = -1.0;
		cast->plane_x = 0.66;
	}
	else if (orientation == 'S')
	{
		cast->dir_y = 1.0;
		cast->plane_x = -0.66;
	}
	else if (orientation == 'E')
	{
		cast->dir_x = 1.0;
		cast->plane_y = 0.66;
	}
	else if (orientation == 'W')
	{
		cast->dir_x = -1.0;
		cast->plane_y = -0.66;
	}
}

void	init_game(t_data *data, t_config *config)
{
	data->player_x = config->player_x;
	data->player_y = config->player_y;
	data->map = config->map;
	data->move_speed = 0.1;
	data->rot_speed = 0.05;
	init_cast(data);
	init_player(data->cast, config->orientation);
}
