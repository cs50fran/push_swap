/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 18:58:42 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort 2 elements - just swap if needed
*/
void	sort_two(t_stack *a)
{
	if (a->top->index > a->top->next->index)
		sa(a);
}

/*
** Sort 3 elements - maximum 2 operations needed
** Strategy:
** 1. If highest is first (pos 0) -> ra (move to bottom)
** 2. If highest is second (pos 1) -> rra (move to bottom)
** 3. If first > second -> sa (swap them)
*/
void	sort_three(t_stack *a)
{
	int	highest_pos;

	highest_pos = find_max_index(a);
	if (highest_pos == 0)
		ra(a);
	else if (highest_pos == 1)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

/*
** Sort 4 elements - push smallest to b, sort 3, push back
*/
void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

/*
** Sort 5 elements - push 2 smallest to b, sort 3, push back
*/
void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
