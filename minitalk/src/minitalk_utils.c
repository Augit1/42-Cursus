/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:39:28 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/23 13:38:04 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

volatile sig_atomic_t	g_ack_received = 0;

char	bit_to_c(char *octet)
{
	char	c;
	int		j;

	c = 0;
	j = -1;
	while (++j < 8)
		c |= (octet[j] << (7 - j));
	return (c);
}

int	manage_sig(int sig, pid_t sender_pid)
{
	int	bit;

	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	else
		exit(1);
	usleep(30);
	if (kill(sender_pid, SIGUSR1) == -1)
	{
		ft_printf("Error sending acknowledgment");
		exit(1);
	}
	return (bit);
}

static void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	secure_kill(pid_t pid, int sig)
{
	struct sigaction	sa;

	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		ft_printf("\n\nError with the acknowledgment signal\n");
		exit(1);
	}
	if (kill(pid, sig) != 0)
	{
		ft_printf("\n\nError check if: ");
		ft_printf("\n\t- The pid: %d is OK", pid);
		ft_printf("\n\t- seveur is UP\n");
		exit(1);
	}
	while (!g_ack_received)
		pause();
	usleep(20);
	g_ack_received = 0;
}

void	print_init(char **txt, int *l)
{
	ft_printf("%s\n", *txt);
	free(*txt);
	*txt = NULL;
	*l = 0;
}
