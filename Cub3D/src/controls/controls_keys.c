/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:31:05 by aude-la-          #+#    #+#             */
/*   Updated: 2025/02/13 18:13:47 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

void	controls_key(int keycode, t_data *data)
{
	if (keycode == LEFT_KEY)
		rotate_left(data, data->rot_speed);
	else if (keycode == RIGHT_KEY)
		rotate_right(data, data->rot_speed);
	else if (keycode == A_KEY)
		move_left(data, data->rot_speed);
	else if (keycode == D_KEY)
		move_right(data, data->rot_speed);
	else if (keycode == W_KEY || keycode == UP_KEY)
		move_forward(data, data->move_speed);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		move_backward(data, data->move_speed);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	else if (keycode == PLUS_KEY || keycode == NUM_PLUS_KEY)
	{
		if (data->move_speed * 1.01 < 1.01)
			data->move_speed *= 1.01;
		if (data->rot_speed * 1.01 < 1.01)
			data->rot_speed *= 1.01;
	}
	else if (keycode == MINUS_KEY || keycode == NUM_MINUS_KEY)
	{
		if (data->move_speed / 1.01 > 0.01)
			data->move_speed /= 1.01;
		if (data->rot_speed / 1.01 > 0.01)
			data->rot_speed /= 1.01;
	}
	else
		controls_key(keycode, data);
	return (draw_raycast(data), 0);
}
