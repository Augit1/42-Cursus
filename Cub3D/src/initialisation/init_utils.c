/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:09:23 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 18:24:54 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialisation.h"

int	init_errors(t_error type, void **ptr)
{
	if (ptr)
		ft_secure_free(ptr);
	write(2, "Error\n", 6);
	if (type == MLX)
		ft_putstr_fd("Failed to init the MiniLibX\n", 2);
	else if (type == MALLOC)
		ft_putstr_fd("Bad memory allocation\n", 2);
	else if (type == WINDOW)
		ft_putstr_fd("Failed to open window\n", 2);
	else if (type == TEXTURE)
		ft_putstr_fd("Failed to load the textures\n", 2);
	return (EXIT_FAILURE);
}

void	create_window(t_data *data)
{
	data->win_width = WIDTH;
	data->win_height = HEIGHT;
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "Cube3D");
	if (!data->win)
		exit(init_errors(WINDOW, (void **)&data->mlx));
}

int	close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(0);
	return (0);
}
