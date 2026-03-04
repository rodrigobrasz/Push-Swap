/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:19:25 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/03/03 11:05:34 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		len;

	if (ac < 2)
		return (0);
	stack_a = create_stack();
	stack_fill(av, stack_a);
	stack_b = create_stack();
	if (is_sorted(stack_a->root))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	indexation(stack_a);
	len = size_list(stack_a->root);
	if (len <= 5)
		small_sort(stack_a, stack_b, len);
	else
		radix_sort(stack_a, stack_b, len);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
