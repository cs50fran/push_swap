/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 15:23:40 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find the position of the minimum index in the stack
*/
int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_idx;
	int		min_pos;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	min_idx = current->index;
	min_pos = 0;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->index < min_idx)
		{
			min_idx = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

/*
** Find the position of the maximum index in the stack
*/
int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_idx;
	int		max_pos;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	max_idx = current->index;
	max_pos = 0;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

/*
** Rotate stack a to bring the minimum index to top, then push to b
** Uses the most efficient rotation direction
*/
void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_index(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < a->size)
		{
			rra(a);
			min_pos++;
		}
	}
	pb(a, b);
}
