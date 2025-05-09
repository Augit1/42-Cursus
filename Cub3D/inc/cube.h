/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:29:51 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 18:56:22 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "libft.h"

typedef struct s_data	t_data;

typedef struct s_config
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		map_width;
	int		map_height;
	double	player_x;
	double	player_y;
	char	orientation;
	t_data	*data;
}			t_config;

typedef enum e_error
{
	MALLOC,
	IDENTIFIER,
	FD,
	READ,
	ARGUMENT,
	CONFIG,
	COLOR,
	MAP_CHAR,
	MAP_CLOSED,
	MAP_PLAYER,
	MLX,
	WINDOW,
	TEXTURE
}			t_error;

#endif
