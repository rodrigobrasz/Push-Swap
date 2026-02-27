/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:00:02 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/27 02:22:36 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack	*stack_a, int wrt)
{
	t_node	*reverse_a;

	if (!stack_a || size_list(stack_a->root) < 2)
		return ;
	reverse_a = pop_bot (stack_a);
	add_top (stack_a, reverse_a);
	if (wrt)
		write(1, "rra\n", 4);
}

void	rrb(t_stack	*stack_b, int wrt)
{
	t_node	*reverse_b;

	if (!stack_b || size_list(stack_b->root) < 2)
		return ;
	reverse_b = pop_top (stack_b);
	add_top (stack_b, reverse_b);
	if (wrt)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra (stack_a, 0);
	rrb (stack_b, 0);
	write(1, "rrr\n", 4);
}
