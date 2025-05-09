/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:23:43 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 18:57:34 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>    // Pour open
# include <unistd.h>   // Pour read et close
# include <stdlib.h>   // Pour exit
# include "libft.h"
# include "initialisation.h"
# include "cube.h"

typedef struct s_file
{
	int		fd;
	ssize_t	bytes_read;
	size_t	len;
	char	buffer[BUFFER_SIZE];
	char	*tmp;
}				t_file;

// parser_utils.c
char	is_space(char c);
void	secure_free(void **ptr);
void	free_array(void **array);
void	*pars_errors(t_error type, void **ptr, int fd);

// parser_config.c
void	init_args(t_config **config, int argc, char **argv);
int		init_config(t_config *config, char *str);
int		handle_identifier(t_config *config, char *line);

// parser_config_utils.c
char	*extract_path(const char *line);
int		parse_color(const char *line);
int		check_config(t_config *config);
void	free_config(t_config *config);

// parser_file.c
int		is_valid_file(const char *file);
char	*file_to_string(const char *file);

// parser_map.c
void	init_map_size(t_config *config);
int		is_player(t_config *config, char c, int y, int x);
int		check_map(t_config *config, char **map);
int		is_surrounded(char **map, char c, int i, int j);
int		map_errors(t_error type);

#endif
