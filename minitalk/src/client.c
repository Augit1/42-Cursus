/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:04:31 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/21 20:47:49 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

volatile sig_atomic_t	g_confirm = 0;

void	checker(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "P", 1);
		g_confirm = 1;
	}
}

void	send_c(char c, pid_t pid)
{
	int					i;
	struct sigaction	sa;
//
	sa.sa_handler = checker;
	i = 8;
	while (--i >= 0)
	{
		if (c & (1 << i))
			secure_kill(pid, SIGUSR1);
		else
			secure_kill(pid, SIGUSR2);
		usleep(100);
//		sigaction(SIGUSR2, &sa, NULL);
//		while (!g_confirm)
//			pause();
//		g_confirm = 0;
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
	while (i-- > 0)
		secure_kill(pid, SIGUSR2);
	while (argv[2][i])
		send_c(argv[2][i++], pid);
	i = 8;
	while (i-- > 0)
		secure_kill(pid, SIGUSR2);
	return (0);
}
