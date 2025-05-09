/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:28:12 by aude-la-          #+#    #+#             */
/*   Updated: 2024/12/05 17:57:21 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	is_space(char c)
{
	return (c && (c == ' ' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r'));
}

void	*pars_errors(t_error type, void **ptr, int fd)
{
	if (ptr)
		ft_secure_free(ptr);
	if (fd)
		close(fd);
	write(2, "Error\n", 6);
	if (type == ARGUMENT)
		ft_putstr_fd("This program take 1 argument\n", 2);
	else if (type == FD)
		ft_putstr_fd("Bad file descriptor\n", 2);
	else if (type == MALLOC)
		ft_putstr_fd("Bad memory allocation\n", 2);
	else if (type == READ)
		ft_putstr_fd("Bad reading\n", 2);
	else if (type == IDENTIFIER)
		ft_putstr_fd("Invalid identifier\n", 2);
	else if (type == CONFIG)
		ft_putstr_fd("Bad config file\n", 2);
	else if (type == COLOR)
		ft_putstr_fd("Invalid color format\n", 2);
	return (NULL);
}
