/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:19:25 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/23 00:19:51 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_node	*node;
	int		len;
	int		i;

	if (ac <= 1)
		return (0);

	stack_a = create_stack();
	stack_fill(av, stack_a);

	node = get_top(stack_a->root);
	len = size_list(node);

	i = 0;
	while (node && i < len)
	{
		printf("value: %d  index: %d\n", node->value, node->index);
		node = node->next;
		i++;
	}
	return (0);
}
