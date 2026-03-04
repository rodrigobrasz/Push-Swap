/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:18:00 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/03/04 20:10:41 by rodcaeta         ###   ########.fr       */
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
	if (*str == '-' || *str == '+')
		str++;
	if (*str == 0)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	parse_arg(char *arg, t_stack *stack_a)
{
	char	**nbrs;
	int		j;
	long	nbr;

	nbrs = ft_split(arg, ' ');
	if (!nbrs || !nbrs[0] || nbrs[0][0] == '\0')
		return (free(nbrs), display_error(stack_a, NULL));
	j = 0;
	while (nbrs[j])
	{
		if (!nbr_check(nbrs[j]))
			return (free_split(nbrs), display_error(stack_a, NULL));
		nbr = atol(nbrs[j]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (free_split(nbrs), display_error(stack_a, NULL));
		if (check_duplicate(stack_a, (int)nbr))
			return (free_split(nbrs), display_error(stack_a, NULL));
		add_bot(stack_a, create_node(nbr));
		j++;
	}
	free_split(nbrs);
}

void	stack_fill(char **av, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (av[i])
	{
		parse_arg(av[i], stack_a);
		i++;
	}
}
