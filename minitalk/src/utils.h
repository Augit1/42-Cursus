/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:32:10 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/21 20:31:11 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf.h"

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	secure_kill(pid_t pid, int sig);
int		ft_strlen(char *s);
int		is_all_zeroes(const char *str);

#endif
