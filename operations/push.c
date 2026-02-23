/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:59:59 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/23 00:26:38 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node *a;

	if(!(stack_a || stack_b || stack_b->root))
		return ;
	a = pop_top(stack_b);
	add_top(stack_a, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*b;

	if(!(stack_a || stack_b || stack_a->root))
		return ;
	b = pop_top(stack_a);
	add_top(stack_b, b);
	write(1, "pb\n", 3);
}
