/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:44:06 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 15:20:36 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_valid_file(const char *file)
{
	const char	*dot;

	if (!file)
		return (0);
	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		return (0);
	return (ft_strncmp(dot, ".cub", 5) == 0);
}

char	*file_to_string(const char *file)
{
	t_file	f;
	char	*result;

	result = NULL;
	if (!is_valid_file(file))
		return (pars_errors(FD, NULL, 0));
	f.fd = open(file, O_RDONLY);
	if (f.fd < 0)
		return (pars_errors(FD, NULL, 0));
	f.len = 0;
	f.bytes_read = read(f.fd, f.buffer, BUFFER_SIZE);
	while (f.bytes_read > 0)
	{
		f.tmp = ft_secured_realloc(result, f.len, f.len + f.bytes_read + 1);
		if (!f.tmp)
			return (pars_errors(MALLOC, (void **)&result, f.fd));
		result = f.tmp;
		f.buffer[f.bytes_read] = '\0';
		ft_strlcpy(&result[f.len], f.buffer, f.bytes_read + 1);
		f.len += f.bytes_read;
		f.bytes_read = read(f.fd, f.buffer, BUFFER_SIZE);
	}
	if (f.bytes_read < 0)
		return (pars_errors(READ, (void **)result, f.fd));
	return (close(f.fd), result);
}
