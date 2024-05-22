/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:52:19 by aude-la-          #+#    #+#             */
/*   Updated: 2024/02/21 20:52:26 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_no_nl(char **buff_backup_ptr)
{
	char	*line;
	size_t	length;

	length = ft_strlen(*buff_backup_ptr);
	line = malloc((length + 1) * sizeof(char));
	if (!line)
	{
		ft_check_free(buff_backup_ptr);
		return (NULL);
	}
	ft_memcpy(line, *buff_backup_ptr, length);
	line[length] = '\0';
	ft_check_free(buff_backup_ptr);
	return (line);
}

char	*get_one_line(char **buff_backup_ptr)
{
	char	*line;
	size_t	length;
	int		i;

	length = ft_strchr(*buff_backup_ptr, '\n') - *buff_backup_ptr;
	line = malloc(length + 2 * sizeof(char));
	if (!line)
		ft_check_free(buff_backup_ptr);
	if (!line)
		return (NULL);
	i = 0;
	while ((*buff_backup_ptr)[i] != '\n')
	{
		line[i] = (*buff_backup_ptr)[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	length = ft_strlen(*buff_backup_ptr) - length;
	if ((*buff_backup_ptr)[i + 1])
		ft_memcpy(*buff_backup_ptr, &(*buff_backup_ptr)[i + 1], length);
	else
		ft_check_free(buff_backup_ptr);
	return (line);
}

void	ft_read_file(char **buff_backup_ptr, char **line_ptr, int fd)
{
	char		*tmp_buff;
	ssize_t		bytes_read;

	tmp_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buff)
	{
		ft_check_free(buff_backup_ptr);
		return ;
	}
	bytes_read = read(fd, tmp_buff, BUFFER_SIZE);
	if (bytes_read == 0 && **buff_backup_ptr)
	{
		ft_check_free(&tmp_buff);
		*line_ptr = ft_no_nl(buff_backup_ptr);
		return ;
	}
	else if (bytes_read <= 0)
	{
		ft_check_free(&tmp_buff);
		ft_check_free(buff_backup_ptr);
		return ;
	}
	tmp_buff[bytes_read] = '\0';
	*buff_backup_ptr = ft_strjoin(buff_backup_ptr, tmp_buff);
	ft_check_free(&tmp_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff_backup;
	char		*line_no_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_no_nl = NULL;
	if (!buff_backup)
	{
		buff_backup = malloc(1);
		if (!buff_backup)
			return (NULL);
		*buff_backup = '\0';
	}
	else if (ft_strchr(buff_backup, '\n'))
		return (get_one_line(&buff_backup));
	ft_read_file(&buff_backup, &line_no_nl, fd);
	if (line_no_nl)
		return (line_no_nl);
	if (!buff_backup)
		return (NULL);
	if (!ft_strchr(buff_backup, '\n'))
		return (get_next_line(fd));
	return (get_one_line(&buff_backup));
}
