/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:22:30 by telufulu          #+#    #+#             */
/*   Updated: 2024/11/15 19:50:10 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"	// t_data, ft_shell_error
#include "lexer.h"		// t_token, num_cmd, get_cmd, get_path
#include "libft.h"		// ft_printf, ft_new_matrix_str
#include "parser.h"		// PIPE

t_token	**next_cmd(t_token **tokens, t_cmd *c)
{
	char	**aux;

	while (tokens && *tokens)
	{
		if ((*tokens)->type == COMMAND)
		{
			aux = c->ex_argv;
			c->ex_argv = ft_matrixjoin(c->ex_argv, (*tokens)->str);
			ft_free_matrix(aux);
		}
		else if ((*tokens)->type == PIPE)
			return (tokens + 1);
		++tokens;
	}
	return (NULL);
}

void	main_lexer(t_data *d, t_token **tokens)
{
	size_t	i;
	char	**sp_path;
	t_cmd	*last;

	i = 0;
	last = NULL;
	d->n_cmd = num_cmd(tokens);
	sp_path = split_path(d->env);
	while (i < d->n_cmd && tokens)
	{
		last = add_cmd(d);
		last->cmd = get_cmd(tokens);
		last->path = get_path(sp_path, last->cmd);
		last->infd = get_fd(tokens, REDIRECT_IN);
		last->outfd = get_fd(tokens, REDIRECT_OUT);
		last->appendfd = get_fd(tokens, APPEND);
		last->heredoc = get_heredoc(tokens);
		last->index = i++;
		last->input = tokens;
		last->data = d;
		tokens = next_cmd(tokens, last);
	}
	ft_free_matrix(sp_path);
}
