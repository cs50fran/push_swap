/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:00:00 by fdinis-d          #+#    #+#             */
/*   Updated: 2026/02/09 00:00:00 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find position of node with highest index in stack B
*/
static int	find_max_pos(t_stack *b)
{
	t_node	*curr;
	t_node	*max_node;
	int		max_pos;
	int		i;

	curr = b->top;
	max_node = curr;
	max_pos = 0;
	i = 0;
	while (i < b->size)
	{
		if (curr->index > max_node->index)
		{
			max_node = curr;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

/*
** Rotate B to bring max element to top using shortest path
*/
static void	rotate_max_to_top(t_stack *b)
{
	int	max_pos;

	max_pos = find_max_pos(b);
	if (max_pos <= b->size / 2)
	{
		while (max_pos-- > 0)
			rb(b);
	}
	else
	{
		max_pos = b->size - max_pos;
		while (max_pos-- > 0)
			rrb(b);
	}
}

/*
** Push all elements from B back to A
** Always push the largest element first (already at correct position)
*/
void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		rotate_max_to_top(b);
		pa(a, b);
	}
}
