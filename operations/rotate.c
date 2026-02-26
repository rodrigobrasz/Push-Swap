/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:00:06 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/26 22:39:07 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int wrt)
{
	t_node	*rotate_a;

	if (!stack_a || size_list(stack_a->root) < 2)
		return ;
	rotate_a = pop_top (stack_a);
	add_bot (stack_a, rotate_a);
	if (wrt)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int wrt)
{
	t_node	*rotate_b;

	if (!stack_b || size_list(stack_b->root) < 2)
		return ;
	rotate_b = pop_top (stack_b);
	add_bot (stack_b, rotate_b);
	if (wrt)
		write(1, "rb\n", 3);
}

void	rr(t_stack	*stack_a, t_stack *stack_b)
{
	ra (stack_a, 0);
	rb (stack_b, 0);
	write(1, "rr\n", 3);
}
