/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:19:25 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/03/02 12:23:05 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_stack(t_stack *s)
{
	t_node	*cur;
	int		guard = 0;

	if (!s || !s->root)
		return (printf("(empty)\n"), (void)0);

	cur = get_bot(s->root);
	while (cur && guard++ < 100)
	{
		printf("Value[%d]    Index[%d]\n", cur->value, cur->index);
		cur = cur->next;
	}
	if (cur)
		printf("STOP:\n");
}*/

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		len;
	if (ac < 2)
		return (0);
	stack_a = create_stack();
	stack_b = create_stack();
	stack_fill(av, stack_a);
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
