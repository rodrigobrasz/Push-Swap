/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:13:43 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/26 22:54:09 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_top(t_stack *lst, t_node *new_top)
{
	t_node	*top;

	if (!lst || !new_top)
		return ;
	if (!lst->root)
	{
		lst->root = new_top;
		new_top->next = NULL;
		new_top->prev = NULL;
		return ;
	}
	top = get_top(lst->root);
	top->next = new_top;
	new_top->prev = top;
	new_top->next = NULL;
}

void	add_bot(t_stack *lst, t_node *new_bot)
{
	t_node	*bot;

	if (!lst || !new_bot)
		return ;
	if (!lst->root)
	{
		lst->root = new_bot;
		new_bot->prev = NULL;
		new_bot->next = NULL;
		return ;
	}
	bot = get_bot(lst->root);
	bot->prev = new_bot;
	new_bot->next = bot;
	new_bot->prev = NULL;
	lst->root = new_bot;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*pop;

	if (!stack || !stack->root)
		return (NULL);
	pop = get_top(stack->root);
	if (pop->prev)
		pop->prev->next = NULL;
	else
		stack->root = NULL;
	pop->next = NULL;
	pop->prev = NULL;
	return (pop);
}

t_node	*pop_bot(t_stack *stack)
{
	t_node	*pop;

	if (!stack)
		return (0);
	pop = get_bot(stack->root);
	if (pop->prev)
		pop->next = NULL;
	if (pop->next)
		pop->next->prev = NULL;
	stack->root = pop->next;
	pop->next = NULL;
	pop->prev = NULL;
	return (pop);
}

int	size_list(t_node *lst)
{
	int	i;

	i = 0;
	lst = get_bot(lst);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
