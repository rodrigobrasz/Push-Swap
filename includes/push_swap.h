/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:59:32 by rodcaeta          #+#    #+#             */
/*   Updated: 2026/02/26 22:44:09 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*root;
}					t_stack;

//Erros File:
void	display_error(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_node *lst);

//Parsing Files:
int		check_duplicate(t_stack *stack_a, int nbr);
int		nbr_check(char *str);

//Indexation:
void	clear_index(t_node *lst);
t_node	*next_index(t_node *lst);
void	indexation(t_stack *stack);

//Stack Init:
t_stack	*create_stack(void);
t_node	*create_node(int value);
t_node	*pop_top(t_stack *lst);
t_node	*pop_bot(t_stack *lst);
void	add_bot(t_stack *lst, t_node *new_bot);
void	add_top(t_stack *lst, t_node *new_top);
int		size_list(t_node *lst);

//Stack Helpers:
void	stack_fill(char **av, t_stack *stack_a);
t_node	*get_top(t_node *node);
t_node	*get_bot(t_node *node);

//Utils:
char	**ft_split(char const *str, char delim);
long	ft_atol(const char *str);

//Moves:
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int wrt);
void	rra(t_stack	*stack_a, int wrt);
void	rb(t_stack *stack_a, int wrt);
void	rrb(t_stack	*stack_b, int wrt);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a, int wrt);
void	sb(t_stack *stack_a, int wrt);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	two_elements(t_stack *stack_a);

#endif