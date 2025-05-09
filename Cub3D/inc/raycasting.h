/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:45:26 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/06 13:28:08 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <mlx.h>
# include <math.h>

typedef struct s_data	t_data;

typedef struct s_cast
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	// Variables pour chaque rayon
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	// Position dans la carte
	int		map_x;
	int		map_y;

	// Distances
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;

	// Étapes et côté
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	// Dessin de la ligne
	int		line_height;
	int		draw_start;
	int		draw_end;

	// Coordonnées de texture
	int		tex_x;
	int		tex_y;

	// Variables pour la texture du mur
	void	*westwall_texture;
	int		westwall_bits_per_pixel;
	int		westwall_size_line;
	int		westwall_endian;
	char	*westwall_addr;

	// Variables pour la texture du mur
	void	*eastwall_texture;
	int		eastwall_bits_per_pixel;
	int		eastwall_size_line;
	int		eastwall_endian;
	char	*eastwall_addr;

	// Variables pour la texture du mur
	void	*northwall_texture;
	int		northwall_bits_per_pixel;
	int		northwall_size_line;
	int		northwall_endian;
	char	*northwall_addr;

	// Variables pour la texture du mur
	void	*southwall_texture;
	int		southwall_bits_per_pixel;
	int		southwall_size_line;
	int		southwall_endian;
	char	*southwall_addr;

	// Dimensions de la texture
	int		tex_width;
	int		tex_height;

	// Variables pour l'image à dessiner
	int		img_bits_per_pixel;
	int		img_size_line;
	int		img_endian;
	char	*img_addr;
	void	*image;
}			t_cast;

// raycasting.c
void	initialize_image(t_data *data, t_cast *cast);
void	draw_raycast(t_data *data);

// raycasting_maths.c
void	calculate_ray(int x, t_data *data, t_cast *cast);
void	calculate_step_and_side_dist(t_data *data, t_cast *cast);
void	calculate_wall_distance(t_data *data, t_cast *cast);
void	calculate_line_height(t_data *data, t_cast *cast);
void	calculate_texture_coordinates(t_data *data, t_cast *cast);

// raycasting_utils.c
char	*select_wall_texture(t_cast *cast);
void	draw_colors(t_data *data);
void	draw_vertical_line(int x, t_data *data, t_cast *cast);
void	perform_dda(t_data *data, t_cast *cast);

#endif
