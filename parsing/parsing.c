/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:18:00 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/23 00:09:59 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	duplicate_check(t_stack *stack_a)
{
	t_node	*temp;
	t_node	*current;

	if (!stack_a || !stack_a->root)
		return (0);
	current = stack_a->root;
	while (current && current->next)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;	
		}
		current = current->next;
	}
	return (0);
}

void	stack_fill(char **av, t_stack *stack_a)
{
	int		i;
	long	nbr;
	t_node	*new_node;
	
	i = 0;
	while(av[i])
	{
		if(!nbr_check(av[i]))
			return(display_error(stack_a, NULL));
		nbr = atol(av[i]);
		if(nbr > INT_MAX || nbr < INT_MIN)
			return (display_error(stack_a, NULL));
		if(duplicate_check(stack_a))
			return(display_error(stack_a, NULL));
		new_node = create_node(nbr);
		add_bot(stack_a, new_node);
		i++;
	}
}
