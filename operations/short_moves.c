/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:26:37 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/27 01:11:45 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_index(t_stack *stack, int index)
{
	t_node	*node;

	node = stack->root;
	while(node)
	{
		if(node->index == index)
			return(node);
		node = node->next;
	}
	return (NULL);
}

void	three_elements(t_stack *stack_a, int index)
{
	t_node	*biggest;

	biggest = find_index(stack_a, index);
	if (!biggest)
		return ;
	if(biggest->index == stack_a->root->index)
		ra(stack_a, 1);
	else if (biggest->index == stack_a->root->next->index)
		ra(stack_a, 1);
	if(stack_a->root->index > stack_a->root->next->index)
		sa(stack_a, 1);
}

void	four_elements(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	t_node	*last_node;

	last_node = get_bot(stack_a->root);
	if (stack_a->root->next->index == min)
		sa(stack_a, 1);
	else if (last_node->index == min || last_node->prev->index == min)
		while (stack_a->root->index != min)
		ra(stack_a, 1);
	if (stack_a->root->index == min)
		pb (stack_a, stack_b);
	three_elements (stack_a, max);
	pa (stack_a, stack_b);
}

void	five_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*next;
	t_node	*last;

	next = stack_a->root->next;
	last = stack_a->root;
	while(last->next)
		last = last->next;
	if (next->index == 0)
		sa(stack_a, 1);
	else if (next->next->index == 0)
	{
		ra (stack_a, 1);
		ra (stack_a, 1);
	}
	else if (last->index == 0 || last->prev->index == 0)
		while (stack_a->root->index != 0)
			rra(stack_a, 1);
	if (stack_a->root->index == 0)
		pb (stack_a, stack_b);
	four_elements(stack_a, stack_b, 4, 1);
	pa (stack_a, stack_b);
	
}


void	small_sort(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 5)
		five_elements(stack_a, stack_b);
	else if (len == 4)
		four_elements(stack_a, stack_b, 3, 0);
	else if (len == 3)
		three_elements(stack_a, 2);
	else if (len == 2)
	{
		if (stack_a->root->index > stack_a->root->next->index)
			sa(stack_a, 1);
	}
}