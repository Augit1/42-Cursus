/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:07:20 by aude-la-          #+#    #+#             */
/*   Updated: 2025/02/13 18:03:09 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALISATION_H
# define INITIALISATION_H

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1200
# endif

# include <mlx.h>
# include "raycasting.h"
# include "controls.h"
# include "cube.h"

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	double		player_x;
	double		player_y;
	double		move_speed;
	double		rot_speed;
	char		**map;
	t_config	*config;
	t_cast		*cast;
}				t_data;

// init_display.c
void	init_mlx(t_data *data);
void	display_values(t_data *data);
void	display_image(t_data *data, t_cast *cast);
void	init_display(t_config *config);

// init_game.c
void	init_cast(t_data *data);
void	init_player(t_cast *cast, char orientation);
void	init_game(t_data *data, t_config *config);

// init_texture.c
void	load_textures(t_data *data);
void	get_texture_addr(t_data *data);
void	handle_texture_error(t_data *data);

// init_utils.c
int		init_errors(t_error type, void **ptr);
void	create_window(t_data *data);
int		close_window(t_data *data);

#endif
