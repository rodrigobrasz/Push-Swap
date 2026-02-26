/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:19:25 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/26 22:16:14 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	t_node	*cur;
	int		guard = 0;

	if (!s || !s->root)
		return (printf("(empty)\n"), (void)0);

	cur = get_top(s->root);
	while (cur && guard++ < 100)
	{
		printf("Value[%d]    Index[%d]\n", cur->value, cur->index);
		cur = cur->prev;
	}
	if (cur)
		printf("STOP:\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_node	*node;
	int		len;
	int		i;

	if (ac <= 1)
		return (0);
	stack_a = create_stack();
	stack_b = create_stack();
	stack_fill(av, stack_a);
	indexation(stack_a);
	node = get_top(stack_a->root);
	len = size_list(node);
	(void)i;
	(void)len;

/*	printf("INDEX TEST:\n");
	while (node && i < len)
	{
		printf("Value [%d] | Index[%d]\n", node->value, node->index);
		node = node->prev;
		i++;
	}*/
/*	printf("=============================\n");
	printf("Move Check\nPB:\nStack A\n");
	print_stack(stack_a);
	printf("Stack B\n");
	pb(stack_a, stack_b);
	print_stack(stack_b);
	printf("=============================\n");
	printf("PA:\nStack B\n");
	print_stack(stack_b);
	pa(stack_a, stack_b);
	print_stack(stack_a);
	printf("=============================\n");
	printf("Sa:\nStack A\n");
	sa(stack_a);
	print_stack(stack_a);
	printf("Sb:\nStack B\n");
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sb(stack_b);
	sb(stack_b);
	print_stack(stack_b);
	printf("=============================\n");
	printf("Ra:\nStack A\n");
	ra(stack_a, 1);
	print_stack(stack_a);*/
/*	printf("=============================\n");
	printf("Stack A\n");
	print_stack(stack_a);
	printf("====\n");
	ra(stack_a, 1);*/
/*	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pa(stack_a, stack_b);
	rb(stack_b, 1);	
	print_stack(stack_a);
	printf("================\n");
	print_stack(stack_b);*/
/*	print_stack(stack_a);*/
	print_stack(stack_a);
	printf("\n");
	printf("=================\n");
	ra(stack_a, 1);
	printf("\n");
	print_stack(stack_a);
	printf("\n");

	free(stack_a);
	free(stack_b);
	return (0);
}
