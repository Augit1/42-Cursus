/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:23:39 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/15 17:26:36 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	checkint(t_stack **stack, char *temp)
{
	if ((*temp && (ft_strlen(temp) > 11))
		|| ((ft_atoi(temp) > INT32_MAX) || (ft_atoi(temp) < INT32_MIN)))
	{
		free_stack(stack);
		error();
	}
}

void	ft_fillstack(int argc, char **argv, t_stack **stack)
{
	int		i;
	char	**temp;
	char	**tab;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			tab = ft_split(argv[i], ' ');
			temp = tab;
			while (*temp)
			{
				checkint(stack, *temp);
				ft_addnode(stack, ft_atoi(*temp));
				free(*temp);
				temp++;
			}
			free(tab);
		}
		else
			(checkint(stack, argv[i]));
		if (!ft_strchr(argv[i], ' '))
			ft_addnode(stack, ft_atoi(argv[i]));
	}
}

void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!*stack)
		return ;
	current = (*stack)->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*stack);
	*stack = NULL;
}
