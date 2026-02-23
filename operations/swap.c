/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:00:04 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/22 23:54:09 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*swap_a;
	t_node	*swap_b;

	if(!stack_a || size_list(stack_a->root) < 2)
		return ;
	swap_a = pop_top(stack_a);
	swap_b = pop_top(stack_a);
	add_top(stack_a, swap_a);
	add_top(stack_a, swap_b);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	t_node	*swap_a;
	t_node	*swap_b;

	if(!stack_b || size_list(stack_b->root) < 2)
		return ;
	swap_a = pop_top(stack_b);
	swap_b = pop_top(stack_b);
	add_top(stack_b, swap_a);
	add_top(stack_b, swap_b);
}

void 	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
