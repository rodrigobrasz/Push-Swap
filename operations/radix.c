/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:24:05 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/03/07 02:42:20 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stk_a, t_stack *stk_b, int len)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	while ((len - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if ((stk_a->root->index >> i & 1) == 1)
				ra(stk_a, 1);
			else
				pb(stk_a, stk_b);
			j++;
		}
		while (stk_b->root)
			pa(stk_a, stk_b);
		i++;
	}
}
