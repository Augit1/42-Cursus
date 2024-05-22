/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:17:30 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/15 22:04:55 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_ptr, char which)
{
	t_stack	*stack;
	t_node	*first;
	t_node	*second;

	stack = *stack_ptr;
	if (stack->head != NULL && stack->head->next != NULL)
	{
		first = stack->head;
		second = stack->head->next;
		first->next = second->next;
		second->next = first;
		stack->head = second;
	}
	if (which == 'a')
		write(1, "sa\n", 3);
	else if (which == 'b')
		write(1, "sb\n", 3);
}

void	push(t_stack **from_ptr, t_stack **to_ptr, char which)
{
	t_stack	*from;
	t_stack	*to;
	t_node	*node;

	from = *from_ptr;
	to = *to_ptr;
	if (from->head != NULL)
	{
		node = from->head;
		from->head = from->head->next;
		node->next = to->head;
		to->head = node;
	}
	from->size--;
	to->size++;
	if (which == 'a')
		write(1, "pa\n", 3);
	else if (which == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack **stack_ptr, char which)
{
	t_stack	*stack;
	t_node	*first;
	t_node	*current;

	stack = *stack_ptr;
	if (stack->head != NULL && stack->head->next != NULL)
	{
		first = stack->head;
		current = stack->head;
		while (current->next != NULL)
			current = current->next;
		stack->head = first->next;
		first->next = NULL;
		current->next = first;
	}
	if (which == 'a')
		write(1, "ra\n", 3);
	else if (which == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack_ptr, char which)
{
	t_stack	*stack;
	t_node	*last;
	t_node	*second_to_last;

	stack = *stack_ptr;
	if (stack->head != NULL && stack->head->next != NULL)
	{
		last = stack->head;
		second_to_last = NULL;
		while (last->next != NULL)
		{
			second_to_last = last;
			last = last->next;
		}
		second_to_last->next = NULL;
		last->next = stack->head;
		stack->head = last;
	}
	if (which == 'a')
		write(1, "rra\n", 4);
	else if (which == 'b')
		write(1, "rrb\n", 4);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}
