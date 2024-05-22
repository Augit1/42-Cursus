/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:36:50 by aude-la-          #+#    #+#             */
/*   Updated: 2024/02/21 21:38:06 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		i;
	char	*line;

	i = 11;
	fd = open("/Users/augustindelabrosse/francinette/tests/get_next_line/fsoares/giant_line_nl.txt", O_RDONLY);
	fd2 = open("/Users/augustindelabrosse/francinette/tests/get_next_line/fsoares/lines_around_10.txt", O_RDONLY);
	fd3 = open("/Users/augustindelabrosse/francinette/tests/get_next_line/fsoares/multiple_nl.txt", O_RDONLY);
	while (i > 8)
	{
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		printf("%s", line);
		if (line)
			free(line);
		i--;
	}
	while (i > 5)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		if (line)
			free(line);
		i--;
	}
	while (i > 3)
	{
		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		printf("%s", line);
		if (line)
			free(line);
		i--;
	}
	close(fd);
	close(fd2);
	close(fd3);
//	system("leaks a.out");
	return (0);
}
