/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:13:43 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/27 03:03:13 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_top(t_stack *lst, t_node *new_top)
{
	if (!lst || !new_top)
		return ;
	
	new_top->prev = NULL;
	new_top->next = lst->root;
	
	if (lst->root)
		lst->root->prev = new_top;
	
	lst->root = new_top;
}

void	add_bot(t_stack *lst, t_node *new_bot)
{
	t_node	*last;

	if (!lst || !new_bot)
		return ;
	
	if (!lst->root)
	{
		lst->root = new_bot;
		new_bot->prev = NULL;
		new_bot->next = NULL;
		return ;
	}
	
	last = lst->root;
	while (last->next)
		last = last->next;
	
	last->next = new_bot;
	new_bot->prev = last;
	new_bot->next = NULL;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*pop;

	if (!stack || !stack->root)
		return (NULL);
	
	pop = stack->root;
	stack->root = pop->next;
	
	if (stack->root)
		stack->root->prev = NULL;
	
	pop->next = NULL;
	pop->prev = NULL;
	
	return (pop);
}

t_node	*pop_bot(t_stack *stack)
{
	t_node	*pop;

	if (!stack || !stack->root)
		return (NULL);
	
	pop = stack->root;
	while (pop->next)
		pop = pop->next;
	
	if (pop->prev)
		pop->prev->next = NULL;
	else
		stack->root = NULL;
	
	pop->prev = NULL;
	pop->next = NULL;
	
	return (pop);
}

int	size_list(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}