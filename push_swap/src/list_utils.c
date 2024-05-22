/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:29:29 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/20 12:10:14 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_addback(t_stack **lst, t_node *new)
{
	t_node	*current;

	if (!new)
		return ;
	if (!*lst || !(*lst)->head)
	{
		(*lst)->head = new;
		return ;
	}
	current = (*lst)->head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

t_node	*ft_newnode(int value)
{
	t_node	*element;

	element = (t_node *) malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->value = value;
	element->index = 0;
	element->next = NULL;
	return (element);
}

void	ft_addnode(t_stack **stack, int value)
{
	t_node	*new_node;

	new_node = ft_newnode(value);
	if (!new_node)
	{
		free_stack(stack);
		error();
	}
	ft_addback(stack, new_node);
	(*stack)->size++;
}
