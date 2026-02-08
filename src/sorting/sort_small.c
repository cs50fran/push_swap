/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/01 19:05:34 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort 2 elements - just swap if needed
*/
void	sort_two(t_stack *a)
{
	if (a->top->index > a->top->next->index)
		sa(a, 1);
}

/*
** Sort 3 elements - maximum 2 operations needed
** Possible patterns (using indices 0,1,2):
** 0 1 2 -> sorted
** 0 2 1 -> sa rra
** 1 0 2 -> sa
** 1 2 0 -> rra
** 2 0 1 -> ra
** 2 1 0 -> sa ra
*/
void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

/*
** Sort 4 elements - push smallest to b, sort 3, push back
*/
void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b, 1);
}

/*
** Sort 5 elements - push 2 smallest to b, sort 3, push back
*/
void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
