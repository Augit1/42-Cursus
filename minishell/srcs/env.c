/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:10:07 by telufulu          #+#    #+#             */
/*   Updated: 2024/11/18 01:01:08 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" //t_data
#include "libft.h" // ft_calloc, ft_strdup, ft_strnstr, ft_strlen,

char	*get_env(char **env, char *var)
{
	size_t	var_len;

	var_len = ft_strlen(var);
	if (!env)
		return (NULL);
	while (*env)
	{
		if (!ft_strncmp(*env, var, var_len))
		{
			if ((*env)[var_len] && (*env)[var_len] == '=')
				return (*env + var_len + 1);
			else if ((*env)[var_len] && (*env)[var_len] != '=')
				return (NULL);
			return (*env + var_len);
		}
		env++;
	}
	return (NULL);
}

int	env_except(char *envp, char **res, int *i)
{
	char	*aux;

	if (ft_strnstr(envp, "OLDPWD", 6))
		return (1);
	else if (ft_strnstr(envp, "SHLVL", 5))
	{
		++(*i);
		aux = ft_itoa(ft_atoi(envp + 6) + 1);
		free(*res);
		*res = ft_strjoin("SHLVL=", aux);
		free(aux);
		return (1);
	}
	return (0);
}

char	**init_env(char **envp)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_calloc(sizeof(char *), ft_matrix_len(envp) + 2);
	if (!res)
		return (NULL);
	while (envp && envp[j])
	{
		if (env_except(envp[j], res + i, &i))
			++j;
		else
		{
			res[i] = ft_strdup(envp[j]);
			if (!res[i])
				return (ft_free_matrix(res));
			++i;
			++j;
		}
	}
	res[i++] = ft_strdup("OLDPWD");
	res[i] = NULL;
	return (res);
}
