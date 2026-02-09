/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 10:37:46 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Update position for all nodes in a stack
** Position is the node's current index from top (0-indexed)
** sets above_median by comparing pos w/ size / 2
*/
void	set_positions(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		current->pos = i;
		current->above_median = (i <= stack->size / 2);
		current = current->next;
		i++;
	}
}

/*
** Find the closest smaller value in B for a node in A
** Returns max of B if no smaller value exists
*/
static t_node	*find_target_in_b(t_node *node_a, t_stack *b)
{
	t_node	*curr_b;
	t_node	*target;
	int		j;

	curr_b = b->top;
	target = NULL;
	j = 0;
	while (j < b->size)
	{
		if (curr_b->value < node_a->value)
			if (!target || curr_b->value > target->value)
				target = curr_b;
		curr_b = curr_b->next;
		j++;
	}
	if (!target)
		target = stack_get_max(b);
	return (target);
}

/*
** Set target node in B for each node in A
*/
void	set_targets(t_stack *a, t_stack *b)
{
	t_node	*curr_a;
	int		i;

	if (!a || !b || !a->top || !b->top)
		return ;
	curr_a = a->top;
	i = 0;
	while (i < a->size)
	{
		curr_a->target = find_target_in_b(curr_a, b);
		curr_a = curr_a->next;
		i++;
	}
}

/*
** Calculate total cost considering rr/rrr optimization
*/
static void	calc_total_cost(t_node *node)
{
	if (node->above_median == node->target->above_median)
	{
		if (node->cost_a > node->cost_b)
			node->total_cost = node->cost_a;
		else
			node->total_cost = node->cost_b;
	}
	else
		node->total_cost = node->cost_a + node->cost_b;
}

/*
** Calculate cost to bring each node in A to top of A
** and its target to top of B. Total cost considers rr/rrr optimization.
*/
void	set_costs(t_stack *a, t_stack *b)
{
	t_node	*curr_a;
	int		i;

	curr_a = a->top;
	i = 0;
	while (i < a->size)
	{
		if (curr_a->above_median)
			curr_a->cost_a = curr_a->pos;
		else
			curr_a->cost_a = a->size - curr_a->pos;
		if (curr_a->target->above_median)
			curr_a->cost_b = curr_a->target->pos;
		else
			curr_a->cost_b = b->size - curr_a->target->pos;
		calc_total_cost(curr_a);
		curr_a = curr_a->next;
		i++;
	}
}


