/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:19:03 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/27 02:02:33 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_index(t_node *lst)
{
	lst = get_bot (lst);
	while (lst)
	{
		lst->index = -1;
		lst = lst->next;
	}
}

t_node	*next_index(t_node *lst)
{
	t_node	*min;

	lst = get_bot (lst);
	min = NULL;
	while (lst)
	{
		if (lst->index == -1 && (!min || lst->value < min->value))
			min = lst;
		lst = lst->next;
	}
	return (min);
}

void	indexation(t_stack *stack)
{
	t_node	*next;
	int		i;

	i = 0;
	if (!stack || !stack->root)
		return ;
	clear_index (stack->root);
	i = 0;
	while (1)
	{
		next = next_index (stack->root);
		if (!next)
			break ;
		next->index = i;
		i++;
	}
}
