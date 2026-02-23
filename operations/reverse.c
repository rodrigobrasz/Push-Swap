/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 21:00:02 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/22 23:54:09 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack	*stack_a)
{
	t_node	*reverse_a;

	if(!stack_a)
		return ;
	reverse_a = pop_top(stack_a);
	add_bot(stack_a, reverse_a);
}

void	rrb(t_stack	*	stack_b)
{
	t_node	*reverse_b;

	if(!stack_b)
		return ;
	reverse_b = pop_top(stack_b);
	add_bot(stack_b, reverse_b);

}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
