/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:00:00 by fdinis-d          #+#    #+#             */
/*   Updated: 2026/02/09 16:59:24 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculate chunk count based on stack size
*/
static int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	return (11);
}

/*
** Check if top element should be pushed (is in current range)
*/
static int	should_push(t_stack *a, int min_idx, int max_idx)
{
	return (a->top->index >= min_idx && a->top->index <= max_idx);
}

/*
** Find best rotation: positive = ra, negative = rra
** Returns size+1 if no element in range
*/
static int	find_best_rotation(t_stack *a, int min_idx, int max_idx)
{
	t_node	*curr;
	int		pos_up;
	int		pos_down;
	int		i;

	if (should_push(a, min_idx, max_idx))
		return (0);
	curr = a->top;
	pos_up = -1;
	i = 0;
	while (i < a->size)
	{
		if (curr->index >= min_idx && curr->index <= max_idx)
		{
			pos_up = i;
			break ;
		}
		curr = curr->next;
		i++;
	}
	if (pos_up == -1)
		return (a->size + 1);
	pos_down = a->size - pos_up;
	if (pos_up <= pos_down)
		return (pos_up);
	return (-pos_down);
}

/*
** Push all elements in range [min_idx, max_idx] to B
*/
static void	push_range_to_b(t_stack *a, t_stack *b, int min_idx, int max_idx)
{
	int	rotation;
	int	mid_idx;

	mid_idx = min_idx + (max_idx - min_idx) / 2;
	while (1)
	{
		rotation = find_best_rotation(a, min_idx, max_idx);
		if (rotation > a->size)
			break ;
		while (rotation > 0)
		{
			ra(a);
			rotation--;
		}
		while (rotation < 0)
		{
			rra(a);
			rotation++;
		}
		pb(a, b);
		if (b->size > 1 && b->top->index < mid_idx)
			rb(b);
	}
}

/*
** Main chunk sorting algorithm
*/
void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_count;
	int	chunk_size;
	int	chunk;
	int	total;

	total = a->size;
	chunk_count = get_chunk_count(total);
	chunk_size = (total + chunk_count - 1) / chunk_count;
	chunk = 0;
	while (chunk < chunk_count && a->size > 0)
	{
		push_range_to_b(a, b, chunk * chunk_size,
			(chunk + 1) * chunk_size - 1);
		chunk++;
	}
	push_back_to_a(a, b);
}
