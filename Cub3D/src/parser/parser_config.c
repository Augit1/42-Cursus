/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:54:45 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/06 17:48:42 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_args(t_config **config, int argc, char **argv)
{
	char	*file_str;

	if (argc != 2 || !argv[1])
		return (pars_errors(ARGUMENT, NULL, 0), exit(EXIT_FAILURE));
	file_str = file_to_string(argv[1]);
	if (!file_str)
		exit(EXIT_FAILURE);
	*config = ft_calloc(1, sizeof(t_config));
	if (!*config || !init_config(*config, file_str))
		return (free_config(*config), exit(EXIT_FAILURE));
}

int	init_config(t_config *config, char *str)
{
	char		*line;
	char		*tmp;

	tmp = str;
	config->floor_color = -1;
	config->ceiling_color = -1;
	while (*tmp)
	{
		line = tmp;
		while (*tmp && *tmp != '\n')
			tmp++;
		if (*tmp == '\n' && (*line != '1' && *line != '0') && !is_space(*line))
			*tmp++ = '\0';
		if (*line == '\0')
			continue ;
		if (!handle_identifier(config, line))
			return (pars_errors(IDENTIFIER, (void **)&str, 0), 0);
		if (config->map)
			break ;
	}
	if (!check_config(config))
		return (pars_errors(CONFIG, (void **)&str, 0), 0);
	return (ft_secure_free((void **)&str), check_map(config, config->map));
}

int	handle_identifier(t_config *config, char *line)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		config->no_texture = extract_path(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		config->so_texture = extract_path(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		config->we_texture = extract_path(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		config->ea_texture = extract_path(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		config->floor_color = parse_color(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		config->ceiling_color = parse_color(line + 2);
	else if (*line == '1' || *line == '0' || is_space(*line))
		config->map = ft_split(line, '\n');
	else
		return (0);
	return (1);
}
