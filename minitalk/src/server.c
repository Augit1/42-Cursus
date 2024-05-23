/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:18:45 by aude-la-          #+#    #+#             */
/*   Updated: 2024/05/23 16:48:51 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

char	*len_receipt(int sig, pid_t sender_pid)
{
	static int	len = 0;
	static char	octet[8] = {0};
	static int	i = 0;
	char		*str;

	octet[i] = manage_sig(sig, sender_pid);
	i++;
	if (i == 8)
	{
		i = 0;
		if (is_all_zeroes(octet))
		{
			str = malloc((len + 1) * sizeof(char));
			if (!str)
				exit(1);
			str[len] = '\0';
			len = 0;
			return (str);
		}
		else
			len = len * 10 + (bit_to_c(octet) - '0');
	}
	return (NULL);
}

void	receipt_c(int sig, siginfo_t *info, void *context)
{
	static char		*txt = NULL;
	static char		octet[8] = {0};
	static int		i = 0;
	static int		l = 0;

	(void)context;
	if (!txt)
	{
		txt = len_receipt(sig, info->si_pid);
		return ;
	}
	octet[i] = manage_sig(sig, info->si_pid);
	i++;
	if (i == 8)
	{
		i = 0;
		if (is_all_zeroes(octet))
			print_init(&txt, &l);
		else if (txt)
			txt[l++] = bit_to_c(octet);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_sigaction = receipt_c;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
