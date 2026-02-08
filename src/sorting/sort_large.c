/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/01 19:05:34 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculate chunk size based on total number of elements
** More chunks = more operations but simpler logic
** Fewer chunks = fewer operations but need smarter placement
*/
static int	get_chunk_size(int total)
{
	if (total <= 100)
		return (20);
	return (55);
}

/*
** Push elements from stack a to b in chunks
** Elements are pushed if their index falls within the current chunk range
** This creates a roughly sorted stack b (larger values toward top)
*/
static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_num;
	int	pushed;
	int	total;

	total = a->size;
	chunk_size = get_chunk_size(total);
	chunk_num = 0;
	pushed = 0;
	while (a->size > 0)
	{
		if (a->top->index <= chunk_num * chunk_size + chunk_size - 1)
		{
			pb(a, b, 1);
			if (b->size > 1 && b->top->index < chunk_num * chunk_size
				+ chunk_size / 2)
				rb(b, 1);
			pushed++;
			if (pushed >= chunk_size || pushed >= total - chunk_num * chunk_size)
			{
				chunk_num++;
				pushed = 0;
			}
		}
		else
			ra(a, 1);
	}
}

/*
** Bring the maximum element to top of b using optimal rotation
*/
static void	bring_max_to_top_b(t_stack *b)
{
	int	max_pos;

	max_pos = find_max_index(b);
	if (max_pos <= b->size / 2)
	{
		while (max_pos > 0)
		{
			rb(b, 1);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < b->size)
		{
			rrb(b, 1);
			max_pos++;
		}
	}
}

/*
** Push all elements back from b to a
** Always push the maximum element first to maintain sorted order
*/
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		bring_max_to_top_b(b);
		pa(a, b, 1);
	}
}

/*
** Main sorting algorithm for large stacks
** Strategy: Chunk-based sorting
** 1. Push elements to b in chunks (roughly sorted)
** 2. Push back to a by always taking the max from b
*/
void	sort_large(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	push_back_to_a(a, b);
}
