/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:28:40 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/11 20:49:42 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "keys.h"
# include <unistd.h>
# include <stdlib.h>

# ifndef LARGEUR
#  define LARGEUR 800
# endif

# ifndef HAUTEUR
#  define HAUTEUR 800
# endif

# ifndef MAX_ITER
#  define MAX_ITER 80
# endif

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	void	(*draw_fractal)(struct s_data *);
	char	*addr;
	char	*name;
	double	zoom;
	double	movex;
	double	movey;
	double	x;
	double	y;
	double	cx;
	double	cy;
	double	x0;
	double	y0;
	double	xtemp;
	int		fractal;
	int		max_iter;
	int		iteration;
	int		color;
	int		color_set[10];
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_anim
{
	int		exist;
	int		steps;
	int		i;
	double	t;
	double	cx_values[10];
	double	cy_values[10];
}				t_anim;

int		mouse_hook(int button, int x, int y, t_data *img);
int		key_hook(int keycode, t_data *img);
int		close_window(t_data *img);
int		ft_putstr(char *str);
int		ft_isdigit(int c);
int		ft_isdouble(char *s);
void	draw(t_data *img);
void	iterate_color(t_data *f, int px, int py);
void	my_mlx_pixel_put(t_data *f, int px, int py);
void	draw_mandelbrot(t_data *f);
void	draw_julia(t_data *f);
void	draw_burningship(t_data *f);
void	display_values(t_data *img, int xp, int yp);
void	init(t_data	*img);
void	args_init(int argc, char **argv, t_data *img);
void	clean_exit(void);
void	animate(t_data *img, int sens);
char	*ft_itoa_double(double n);
double	ft_fabs(double x);
double	ft_atoi_double(const char *str);

#endif
