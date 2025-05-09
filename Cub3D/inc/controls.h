/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:51:08 by aude-la-          #+#    #+#             */
/*   Updated: 2025/02/13 18:14:22 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "initialisation.h"
# include "keys.h"
# include "cube.h"

// controls_move.c
void	move_forward(t_data *data, double move_speed);
void	move_backward(t_data *data, double move_speed);
void	move_left(t_data *data, double move_speed);
void	move_right(t_data *data, double move_speed);

// controls_rotate.c
void	rotate_right(t_data *data, double rot_speed);
void	rotate_left(t_data *data, double rot_speed);

// controls_keys.c
void	controls_key(int keycode, t_data *data);
int		key_hook(int keycode, t_data *data);

#endif
