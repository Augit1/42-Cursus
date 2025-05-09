/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:58:03 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/06 17:06:55 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*extract_path(const char *line)
{
	char	*path;
	int		len;

	while (*line && is_space(*line))
		line++;
	len = 0;
	while (line[len] && !is_space(line[len]))
		len++;
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	ft_strlcpy(path, line, len + 1);
	return (path);
}

int	parse_color(const char *line)
{
	int	t;
	int	r;
	int	g;
	int	b;

	while (*line && is_space(*line))
		line++;
	t = 0;
	r = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	g = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	b = ft_atoi(line);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (pars_errors(COLOR, NULL, 0), -1);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_config(t_config *config)
{
	return (config->no_texture && config->so_texture
		&& config->we_texture && config->ea_texture
		&& config->floor_color >= 0
		&& config->ceiling_color >= 0
		&& config->map);
}

void	free_config(t_config *config)
{
	ft_free_array((void **)config->map);
	ft_secure_free((void **)&config->no_texture);
	ft_secure_free((void **)&config->so_texture);
	ft_secure_free((void **)&config->we_texture);
	ft_secure_free((void **)&config->ea_texture);
	ft_secure_free((void **)&config);
}
