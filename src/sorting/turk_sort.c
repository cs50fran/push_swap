/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 15:42:11 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main Turk sorting algorithm for large stacks
** Strategy:
** 1. Push first 2 nodes to B (no cost calculation needed)
** 2. For each remaining node in A:
**    - Calculate positions, targets, and costs
**    - Find the cheapest node to push
**    - Execute the move
** 3. Push all back from B to A
** 4. Final rotate to put smallest at top
*/

/*
** Find, mark & return the node with the lowest total cost
*/
t_node	*set_cheapest(t_stack *a)
{
	t_node	*curr_a;
	t_node	*cheapest;
	int		i;

	cheapest = a->top;
	curr_a = cheapest;
	curr_a->cheapest = 1;
	i = 0;
	while (i < a->size)
	{
		if (curr_a->total_cost < cheapest->total_cost)
		{
			curr_a->cheapest = 1;
			cheapest->cheapest = 0;
			cheapest = curr_a;
		}
		curr_a = curr_a->next;
		i++;
	}
	return (cheapest);
}

void	push_cheapest_to_b(t_stack *a, t_stack *b)
{
	int		pos_a;
	int		target_b_pos;
	t_node	*cheapest;

	cheapest = set_cheapest(a);
	pos_a = cheapest->pos;
	target_b_pos = cheapest->target->pos;
	do_rotations(a, b, &pos_a, &target_b_pos);
	pb(a, b);
}

/*
** Find the smallest value in A that is greater than node_b
** Returns min of A if no greater value exists
*/
static t_node	*find_target_in_a(t_node *node_b, t_stack *a)
{
	t_node	*curr_a;
	t_node	*target;
	int		i;

	curr_a = a->top;
	target = NULL;
	i = 0;
	while (i < a->size)
	{
		if (curr_a->value > node_b->value)
			if (!target || curr_a->value < target->value)
				target = curr_a;
		curr_a = curr_a->next;
		i++;
	}
	if (!target)
		target = stack_get_min(a);
	return (target);
}

/*
** Push all elements from B back to A in correct positions
*/
void	push_all_to_a(t_stack *a, t_stack *b)
{
	t_node	*target;

	while (b->size > 0)
	{
		set_positions(a);
		target = find_target_in_a(b->top, a);
		rotate_a_to_pos(a, target->pos);
		pa(a, b);
	}
}

void	turk_sort(t_stack *a, t_stack *b)
{
	if (a->size > 3 && !stack_is_sorted(a))
		pb(a, b);
	if (a->size > 3 && !stack_is_sorted(a))
		pb(a, b);
	while (a->size > 3 && !stack_is_sorted(a))
	{
		set_positions(a);
		set_positions(b);
		set_targets(a, b);
		set_costs(a, b);
		push_cheapest_to_b(a, b);
	}
	sort_three(a);
	push_all_to_a(a, b);
	final_rotate(a);
}
