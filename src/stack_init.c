/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:16:22 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/22 23:54:09 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;
	
	if(!(new_stack = malloc(sizeof(t_stack))))
		return (NULL);
	new_stack->root = NULL;
	return (new_stack);
}

t_node	*create_node(int value)
{
	t_node	*new_node;
	
	if(!(new_node = malloc(sizeof(t_node))))
	return (NULL);
new_node->index = -1;
new_node->value = value;
new_node->next = NULL;
new_node->prev = NULL;
return (new_node);
}

void	push_to_stack(t_node *new_node, t_stack *lst)
{
	if(!lst->root)
	{
		lst->root = new_node;
			return ;
	}
	lst->root = get_top(lst->root);
	lst->root->prev = new_node;
	new_node->prev = lst->root;
}
t_node *get_top(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_node *get_bot(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->prev)
		node = node->prev;
	return (node);
}
