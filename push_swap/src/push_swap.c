/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:36:10 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/20 15:19:24 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_maxbits(int max_value)
{
	int		max_bits;

	max_bits = 0;
	while (max_value > 0)
	{
		max_value >>= 1;
		max_bits++;
	}
	return (max_bits);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return (1);
	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_checkinput(argc, argv);
	stack_a = ft_newstack();
	stack_b = ft_newstack();
	if (!stack_a)
		error();
	ft_fillstack(argc, argv, &stack_a);
	ft_checkdouble(stack_a);
	ft_index(stack_a);
	if (is_sorted(stack_a))
		exit(0);
	else if (stack_a->size == 2)
		swap(&stack_a, 'a');
	else if (stack_a->size == 3)
		sort_three(stack_a, stack_a->head);
	else if (stack_a->size < 50)
		sortlist(stack_a, stack_b);
	else
		orderlist(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
