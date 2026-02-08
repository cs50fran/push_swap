/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 11:33:50 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** Stack node structure (doubly-linked list)
** value: the original input value
** index: normalized index (0 to n-1) for easier sorting
*/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/*
** Stack structure
** top: pointer to the top node
** size: number of elements in the stack
*/
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Stack initialization and utilities */
t_stack	*stack_init(void);
t_node	*node_new(int value);
void	stack_push(t_stack *stack, t_node *node);
t_node	*stack_pop(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
t_node	*stack_get_min(t_stack *stack);
t_node	*stack_get_max(t_stack *stack);
int		get_position(t_stack *stack, t_node *node);

/* Operations - Swap */
void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);

/* Operations - Push */
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);

/* Operations - Rotate */
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);

/* Operations - Reverse Rotate */
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);

/* Parsing */
int		parse_args(int argc, char **argv, t_stack *a);
int		is_valid_integer(char *str, long *num);
int		has_duplicates(t_stack *stack, int value);
void	assign_indices(t_stack *stack);

/* Sorting */
void	sort_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);

/* Sorting utilities */
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
void	push_min_to_b(t_stack *a, t_stack *b);

/* Error handling and cleanup */
void	error_exit(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	free_split(char **split);

#endif
