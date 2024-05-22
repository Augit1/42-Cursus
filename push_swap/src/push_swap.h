/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:34:15 by aude-la-          #+#    #+#             */
/*   Updated: 2024/03/20 14:20:37 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
	int		max;
}	t_stack;

int		ft_maxbits(int max_value);
int		is_sorted(t_stack *stack);
int		ft_abs(int nb);
void	ft_index(t_stack *stack);
void	ft_addback(t_stack **lst, t_node *new);
t_node	*ft_newnode(int value);
t_stack	*ft_newstack(void);
void	ft_addnode(t_stack **stack, int value);
void	ft_fillstack(int argc, char **argv, t_stack **stack);
void	free_stack(t_stack **stack);
void	error(void);
void	ft_checkinput(int argc, char **argv);
void	ft_checkdouble(t_stack *stack);
void	swap(t_stack **stack_ptr, char which);
void	push(t_stack **from_ptr, t_stack **to_ptr, char which);
void	rotate(t_stack **stack_ptr, char which);
void	reverse_rotate(t_stack **stack_ptr, char which);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack *stack_a, t_node *first);
void	ft_ordonate(t_stack	*stack_a, t_stack *stack_b, int bit);
void	orderlist(t_stack *stack_a, t_stack *stack_b);
void	pb_min_a(t_stack *stack_a, t_stack *stack_b);
void	sortlist(t_stack *stack_a, t_stack *stack_b);

#endif
