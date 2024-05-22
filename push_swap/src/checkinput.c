/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:03:39 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/20 14:29:20 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

void	ft_checkinput(int argc, char **argv)
{
	int	i;
	int	j;
	int	only_spaces;

	if (argc < 2)
		exit(0);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		only_spaces = 1;
		while (argv[i][++j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == ' '
				|| ((argv[i][j] == '+' || argv[i][j] == '-') &&
				(j == 0 || argv[i][j -1] == ' ') && ft_isdigit(argv[i][j +1]))))
				error();
			if (argv[i][j] != ' ')
				only_spaces = 0;
		}
		if (only_spaces && argv[i][j] != '\0')
			error();
	}
}

void	ft_index(t_stack *stack)
{
	t_node	*current;
	t_node	*minimum;
	int		min;
	int		i;

	i = 0;
	minimum = stack->head;
	while (++i <= stack->size)
	{
		min = stack->max;
		current = stack->head;
		while (current)
		{
			if ((current->value < min) && (current->index == 0))
			{
				minimum = current;
				min = minimum->value;
			}
			else if ((i == stack->size) && (current->index == 0))
				minimum = current;
			current = current->next;
		}
		minimum->index = i;
	}
}

void	ft_checkdouble(t_stack *stack)
{
	t_node	*current;
	t_node	*following;

	current = stack->head;
	stack->max = ft_abs(current->value);
	while (current)
	{
		following = current->next;
		while (following)
		{
			if (following->value == current->value)
			{
				free_stack(&stack);
				error();
			}
			if (ft_abs(following->value) > stack->max)
				stack->max = ft_abs(following->value);
			following = following->next;
		}
		current = current->next;
	}
}
