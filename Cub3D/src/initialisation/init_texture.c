/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:43:25 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 18:25:02 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialisation.h"

void	load_textures(t_data *data)
{
	t_cast	*cast;

	cast = data->cast;
	cast->northwall_texture = mlx_xpm_file_to_image(data->mlx,
			data->config->no_texture, &cast->tex_width, &cast->tex_height);
	if (!cast->northwall_texture)
		handle_texture_error(data);
	cast->southwall_texture = mlx_xpm_file_to_image(data->mlx,
			data->config->so_texture, &cast->tex_width, &cast->tex_height);
	if (!cast->southwall_texture)
		handle_texture_error(data);
	cast->eastwall_texture = mlx_xpm_file_to_image(data->mlx,
			data->config->ea_texture, &cast->tex_width, &cast->tex_height);
	if (!cast->eastwall_texture)
		handle_texture_error(data);
	cast->westwall_texture = mlx_xpm_file_to_image(data->mlx,
			data->config->we_texture, &cast->tex_width, &cast->tex_height);
	if (!cast->westwall_texture)
		handle_texture_error(data);
}

void	get_texture_addr(t_data *data)
{
	t_cast	*cast;

	cast = data->cast;
	cast->northwall_addr = mlx_get_data_addr(cast->northwall_texture,
			&cast->northwall_bits_per_pixel,
			&cast->northwall_size_line,
			&cast->northwall_endian);
	cast->southwall_addr = mlx_get_data_addr(cast->southwall_texture,
			&cast->southwall_bits_per_pixel,
			&cast->southwall_size_line,
			&cast->southwall_endian);
	cast->eastwall_addr = mlx_get_data_addr(cast->eastwall_texture,
			&cast->eastwall_bits_per_pixel,
			&cast->eastwall_size_line,
			&cast->eastwall_endian);
	cast->westwall_addr = mlx_get_data_addr(cast->westwall_texture,
			&cast->westwall_bits_per_pixel,
			&cast->westwall_size_line,
			&cast->westwall_endian);
	if (!cast->northwall_addr || !cast->southwall_addr
		|| !cast->eastwall_addr || !cast->westwall_addr)
		handle_texture_error(data);
}

void	handle_texture_error(t_data *data)
{
	t_cast	*cast;

	cast = data->cast;
	if (cast->northwall_texture)
		mlx_destroy_image(data->mlx, cast->northwall_texture);
	if (cast->southwall_texture)
		mlx_destroy_image(data->mlx, cast->southwall_texture);
	if (cast->eastwall_texture)
		mlx_destroy_image(data->mlx, cast->eastwall_texture);
	if (cast->westwall_texture)
		mlx_destroy_image(data->mlx, cast->westwall_texture);
	if (data->cast)
		free(data->cast);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(init_errors(TEXTURE, NULL));
}
