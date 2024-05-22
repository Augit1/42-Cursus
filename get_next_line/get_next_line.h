/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:52:38 by aude-la-          #+#    #+#             */
/*   Updated: 2024/02/21 20:52:43 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char **s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_check_free(char **s);
void	ft_read_file(char **buff_backup_ptr, char **line_ptr, int fd);
char	*get_one_line(char **buff_backup_ptr);
char	*ft_no_nl(char **buff_backup_ptr);
char	*get_next_line(int fd);

#endif
