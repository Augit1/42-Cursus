/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:18:45 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/21 20:44:39 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*g_txt = NULL;

char	bit_to_c(char *octet, int i, int sig)
{
	char	c;
	int		j;

	c = 0;
	j = -1;
	while (++j < 8)
		c |= (octet[j] << (7 - j));
	i = 0;
	return (c);
}

void	len_receipt(int	sig, siginfo_t *info, void *context)
{
	static int	len = 0;
	static char	octet[8];
	static int	i = 0;

	(void)context;
	if (sig == SIGUSR1)
	{
		octet[i] = 1;
//		secure_kill(info->si_pid, SIGUSR2);
	}
	else if (sig == SIGUSR2)
	{
		octet[i] = 0;
//		secure_kill(info->si_pid, SIGUSR2);
	}
	else
		exit(1);
	i++;
	if (i == 8)
	{
		if (is_all_zeroes(octet))
			g_txt = malloc((len + 1) * sizeof(char));
		else	
		{
			len *= 10;
			len += (bit_to_c(octet, i, sig) - '0');
		}
	}
}

void	receipt_c(int sig, siginfo_t *info, void *context)
{
	static char		octet[8];
	static int		i = 0;
	static int		l = 0;

	(void)context;
	if (sig == SIGUSR1)
	{
		octet[i] = 1;
//		secure_kill(info->si_pid, SIGUSR2);
	}
	else if (sig == SIGUSR2)
	{
		octet[i] = 0;
//		secure_kill(info->si_pid, SIGUSR2);
	}
	else
		exit(1);
	i++;
	if (i == 8)
	{
		if (is_all_zeroes(octet))
		{
			ft_printf("%s\n", g_txt);
			free(g_txt);
			g_txt = NULL;
		}
		else	
			g_txt[l++] = bit_to_c(octet, i, sig);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	if (!g_txt)
		sa.sa_sigaction = len_receipt;
	else
		sa.sa_sigaction = receipt_c;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
