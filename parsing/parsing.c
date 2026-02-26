/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:18:00 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/26 22:45:48 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack_a, int nbr)
{
	t_node	*cur;

	if (!stack_a || !stack_a->root)
		return (0);
	cur = get_bot (stack_a->root);
	while (cur)
	{
		if (cur->value == nbr)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	nbr_check(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	stack_fill(char **av, t_stack *stack_a)
{
	int		i;
	long	nbr;
	t_node	*new_node;

	i = 1;
	while (av[i])
	{
		if (!nbr_check(av[i]))
			return (display_error(stack_a, NULL));
		nbr = atol (av[i]);
		if (nbr >= INT_MAX || nbr <= INT_MIN)
			return (display_error(stack_a, NULL));
		if (check_duplicate(stack_a, (int)nbr))
			return (display_error(stack_a, NULL));
		new_node = create_node (nbr);
		add_bot (stack_a, new_node);
		i++;
	}
}
