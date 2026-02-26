/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:23:40 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/23 01:13:03 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *lst)
{
	if(!lst)
		return ;	
	lst = get_bot(lst);
	while (lst)
	{
		free(lst->prev);
		lst->prev =  NULL;
		lst = lst->next;
	}
	free (lst);
}


void	display_error(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}