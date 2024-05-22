/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:52:11 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/20 15:13:50 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a, t_node *first)
{
	t_node	*second;
	t_node	*third;

	second = first->next;
	third = second->next;
	if ((first->value > second->value) && (second->value > third->value))
	{
		swap(&stack_a, 'a');
		reverse_rotate(&stack_a, 'a');
	}
	else if ((first->value > third->value) && (third->value > second->value))
		rotate(&stack_a, 'a');
	else if ((second->value > third->value) && (first->value > third->value))
		reverse_rotate(&stack_a, 'a');
	else if ((first->value > second->value) && (third->value > first->value))
		swap(&stack_a, 'a');
	else if ((third->value > first->value) && (second->value > third->value))
	{
		swap(&stack_a, 'a');
		rotate(&stack_a, 'a');
	}
}

void	ft_ordonate(t_stack	*stack_a, t_stack *stack_b, int bit)
{
	int	nb;

	if (!stack_a->head)
		return ;
	nb = stack_a->head->index;
	if ((nb >> bit) & 1)
		rotate(&stack_a, 'a');
	else
		push(&stack_a, &stack_b, 'b');
}

void	orderlist(t_stack *stack_a, t_stack *stack_b)
{
	int		bit;
	int		total_bits;
	int		size;
	int		i;

	total_bits = ft_maxbits(stack_a->size);
	bit = 0;
	while (bit < total_bits)
	{
		size = stack_a->size;
		i = -1;
		while (++i < size && !is_sorted(stack_a))
			ft_ordonate(stack_a, stack_b, bit);
		while (stack_b->head)
			push(&stack_b, &stack_a, 'a');
		bit++;
	}
}

void	pb_min_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		index;
	int		min_index;

	index = 0;
	min_index = 0;
	current = stack_a->head;
	stack_a->max = current->value;
	while (current)
	{
		if (current->value < stack_a->max)
			min_index = index;
		if (current->value < stack_a->max)
			stack_a->max = current->value;
		current = current->next;
		index++;
	}
	index = 0;
	if (min_index <= stack_a->size / 2)
		while (min_index-- > 0)
			rotate(&stack_a, 'a');
	else
		while (index++ < stack_a->size - min_index)
			reverse_rotate(&stack_a, 'a');
	push(&stack_a, &stack_b, 'b');
}

void	sortlist(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
	{
		pb_min_a(stack_a, stack_b);
		sort_three(stack_a, stack_a->head);
	}
	else if (stack_a->size == 5)
	{
		pb_min_a(stack_a, stack_b);
		pb_min_a(stack_a, stack_b);
		sort_three(stack_a, stack_a->head);
	}
	else
		while (stack_a->head->next || !is_sorted(stack_a))
			pb_min_a(stack_a, stack_b);
	while (stack_b->head)
		push(&stack_b, &stack_a, 'a');
}
