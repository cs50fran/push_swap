/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:36:02 by fdinis-d          #+#    #+#             */
/*   Updated: 2026/02/09 16:36:16 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_pos(t_stack *stack_a, int pos_a)
{
	int	size;

	size = stack_a->size;
	if (pos_a <= size / 2)
	{
		while (pos_a > 0)
		{
			ra(stack_a);
			pos_a--;
		}
	}
	else
	{
		while (pos_a < size)
		{
			rra(stack_a);
			pos_a++;
		}
	}
}

void	rotate_b_to_pos(t_stack *stack_b, int pos_b)
{
	int	size;

	size = stack_b->size;
	if (pos_b <= size / 2)
	{
		while (pos_b > 0)
		{
			rb(stack_b);
			pos_b--;
		}
	}
	else
	{
		while (pos_b < size)
		{
			rrb(stack_b);
			pos_b++;
		}
	}
}

void	do_rotations(t_stack *stack_a, t_stack *stack_b,
		int *pos_a, int *target_b)
{
	int	a_above_median;
	int	b_above_median;

	a_above_median = (*pos_a <= stack_a->size / 2);
	b_above_median = (*target_b <= stack_b->size / 2);
	while (*pos_a > 0 && *target_b > 0 && a_above_median && b_above_median)
	{
		rr(stack_a, stack_b);
		(*pos_a)--;
		(*target_b)--;
	}
	while (*pos_a < stack_a->size && *target_b < stack_b->size
		&& !a_above_median && !b_above_median)
	{
		rrr(stack_a, stack_b);
		(*pos_a)++;
		(*target_b)++;
	}
	rotate_a_to_pos(stack_a, *pos_a);
	rotate_b_to_pos(stack_b, *target_b);
}

/*
** Rotate A until smallest element is at top
*/
void	final_rotate(t_stack *a)
{
	int	min_pos;

	set_positions(a);
	min_pos = find_min_index(a);
	rotate_a_to_pos(a, min_pos);
}
