/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:04:31 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/23 13:56:00 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	send_c(char c, pid_t pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c & (1 << i))
			secure_kill(pid, SIGUSR1);
		else
			secure_kill(pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	char	*len;

	if (argc < 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	len = ft_itoa(ft_strlen(argv[2]));
	i = 0;
	while (len[i])
		send_c(len[i++], pid);
	free(len);
	i = 8;
	while (--i >= 0)
		secure_kill(pid, SIGUSR2);
	while (argv[2][++i])
		send_c(argv[2][i], pid);
	i = 8;
	while (--i >= 0)
		secure_kill(pid, SIGUSR2);
	return (0);
}
