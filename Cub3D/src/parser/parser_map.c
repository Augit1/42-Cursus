/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:09:24 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/06 16:42:39 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_map_size(t_config *config)
{
	int	y;
	int	x;

	config->map_width = 0;
	config->map_height = 0;
	y = -1;
	while (config->map[++y])
	{
		x = -1;
		while (config->map[y][++x])
			if (x > config->map_width)
				config->map_width = x;
		if (y > config->map_height)
			config->map_height = y;
	}
}

int	is_player(t_config *config, char c, int y, int x)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		config->player_x = x;
		config->player_y = y;
		config->orientation = c;
		return (1);
	}
	return (0);
}

int	check_map(t_config *config, char **map)
{
	int		player;
	int		y;
	int		x;
	char	c;

	player = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			c = map[y][x];
			if (is_player(config, c, y, x))
				player++;
			else if (c != '1' && c != '0' && !is_space(c))
				return (map_errors(MAP_CHAR));
			if (!is_surrounded(map, c, y, x))
				return (map_errors(MAP_CLOSED));
		}
	}
	if (player != 1)
		return (map_errors(MAP_PLAYER));
	init_map_size(config);
	return (1);
}

int	is_surrounded(char **map, char c, int i, int j)
{
	if (c == '1' || is_space(c))
		return (1);
	if (i <= 0 || !map[i + 1] || j <= 0 || !map[i][j + 1])
		return (0);
	if (!map[i - 1] || !map[i - 1][j] || is_space(map[i - 1][j]))
		return (0);
	if (!map[i + 1] || !map[i + 1][j] || is_space(map[i + 1][j]))
		return (0);
	if (!map[i][j - 1] || is_space(map[i][j - 1]))
		return (0);
	if (!map[i][j + 1] || is_space(map[i][j + 1]))
		return (0);
	if ((map[i - 1][j - 1] && is_space(map[i - 1][j - 1]))
		|| !map[i - 1][j - 1])
		return (0);
	if ((map[i - 1][j + 1] && is_space(map[i - 1][j + 1]))
		|| !map[i - 1][j + 1])
		return (0);
	if ((map[i + 1][j - 1] && is_space(map[i + 1][j - 1]))
		|| !map[i + 1][j - 1])
		return (0);
	if ((map[i + 1][j + 1] && is_space(map[i + 1][j + 1]))
		|| !map[i + 1][j + 1])
		return (0);
	return (1);
}

int	map_errors(t_error type)
{
	write(1, "Error\n", 6);
	if (type == MAP_CHAR)
		ft_putstr_fd("Invalid character in the map\n", 2);
	else if (type == MAP_CLOSED)
		ft_putstr_fd("Map not closed\n", 2);
	else if (type == MAP_PLAYER)
		ft_putstr_fd("Invalid number of player\n", 2);
	return (0);
}
