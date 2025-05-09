/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:26:21 by aude-la-          #+#    #+#             */
/*   Updated: 2025/02/13 17:50:53 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

void	move_forward(t_data *data, double move_speed)
{
	char	player;
	int		map_x;
	int		map_y;
	char	pos;

	player = data->config->orientation;
	map_x = (int)(data->player_x + data->cast->dir_x * move_speed);
	map_y = (int)(data->player_y);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_x += data->cast->dir_x * move_speed;
	map_x = (int)(data->player_x);
	map_y = (int)(data->player_y + data->cast->dir_y * move_speed);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_y += data->cast->dir_y * move_speed;
}

void	move_backward(t_data *data, double move_speed)
{
	char	player;
	int		map_x;
	int		map_y;
	char	pos;

	player = data->config->orientation;
	map_x = (int)(data->player_x - data->cast->dir_x * move_speed);
	map_y = (int)(data->player_y);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_x -= data->cast->dir_x * move_speed;
	map_x = (int)(data->player_x);
	map_y = (int)(data->player_y - data->cast->dir_y * move_speed);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_y -= data->cast->dir_y * move_speed;
}

void	move_left(t_data *data, double move_speed)
{
	char	player;
	int		map_x;
	int		map_y;
	char	pos;

	player = data->config->orientation;
	map_x = (int)(data->player_x + data->cast->dir_y * move_speed);
	map_y = (int)(data->player_y);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_x += data->cast->dir_y * move_speed;
	map_x = (int)(data->player_x);
	map_y = (int)(data->player_y - data->cast->dir_x * move_speed);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_y -= data->cast->dir_x * move_speed;
}

void	move_right(t_data *data, double move_speed)
{
	char	player;
	int		map_x;
	int		map_y;
	char	pos;

	player = data->config->orientation;
	map_x = (int)(data->player_x - data->cast->dir_y * move_speed);
	map_y = (int)(data->player_y);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_x -= data->cast->dir_y * move_speed;
	map_x = (int)(data->player_x);
	map_y = (int)(data->player_y + data->cast->dir_x * move_speed);
	pos = data->map[map_y][map_x];
	if (pos == '0' || pos == player)
		data->player_y += data->cast->dir_x * move_speed;
}
