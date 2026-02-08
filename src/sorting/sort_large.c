/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 15:23:40 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate stack to optimal position to bring target to top
** Uses shortest path (ra or rra)
*/
static void	rotate_to_top(t_stack *stack, int pos, char stack_name)
{
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (pos++ < stack->size)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

/*
** Push all elements from A to B in descending order (largest on top)
** Keep only 3 elements in A
*/
static void	push_all_to_b(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (a->size > 3)
	{
		max_pos = find_max_index(a);
		rotate_to_top(a, max_pos, 'a');
		pb(a, b);
	}
}

/*
** Push all elements from B back to A
** B is sorted descending (largest on top), A is sorted ascending
** Just push all - result will be circularly sorted
*/
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		pa(a, b);
}

/*
** Rotate A until smallest element is at top
*/
static void	final_rotate(t_stack *a)
{
	int	min_pos;

	min_pos = find_min_index(a);
	rotate_to_top(a, min_pos, 'a');
}

/*
** Main sorting algorithm for large stacks
** Strategy:
** 1. Push all to B in descending order (largest first), keep 3 in A
** 2. Sort the 3 remaining in A
** 3. Push back from B to A in correct position (both sorted)
** 4. Final rotate to put smallest at top
*/
void	sort_large(t_stack *a, t_stack *b)
{
	push_all_to_b(a, b);
	sort_three(a);
	push_back_to_a(a, b);
	final_rotate(a);
}
