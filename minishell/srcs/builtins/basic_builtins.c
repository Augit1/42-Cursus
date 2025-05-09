/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:51:07 by telufulu          #+#    #+#             */
/*   Updated: 2024/11/17 15:52:27 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"	// t_cmd
#include "libft.h"	//ft_putstr_fd

int	exit_built(t_cmd *c, char **env)
{
	if (!c->next && !c->index && env)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		c->data->exit_status = EXIT_SUCCESS;
		exit(c->data->exit_status);
	}
	return (EXIT_SUCCESS);
}

int	env_built(t_cmd *c, char **env)
{
	int	i;

	i = 0;
	(void)c;
	while (env && env[i])
	{
		if (ft_strchr(env[i], '=') && c)
		{
			ft_putstr_fd(env[i], STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	pwd_built(t_cmd *c, char **env)
{
	char	buff[1000];
	char	*res;

	if (env && c)
	{
		res = getcwd(buff, 1000);
		if (!res)
			res = get_env(env, "PWD");
		ft_putstr_fd(res, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
