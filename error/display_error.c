/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:23:40 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/27 01:33:38 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*ref;
	t_node	*next;
	
	if(!stack)
		return ;
	ref = stack->root;
	while (ref)
	{
		next = ref->next;
		free(ref);
		ref = next;
	}
	free(stack);
}

void	display_error(t_stack *stack_a, t_stack *stack_b)
{
	free (stack_a);
	free (stack_b);
	write(2, "Error\n", 6);
	exit (1);
}
