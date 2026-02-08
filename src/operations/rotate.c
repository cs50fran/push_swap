/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 12:00:36 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate: Shift up all elements by 1. First becomes last.
** With circular doubly-linked list, just move top pointer to next
*/
static void	rotate(t_stack *stack)
{
	if (!stack || !stack->top || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

/*
** ra: Rotate stack a - first element becomes last
*/
void	ra(t_stack *a, int print)
{
	rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/*
** rb: Rotate stack b - first element becomes last
*/
void	rb(t_stack *b, int print)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/*
** rr: ra and rb at the same time
*/
void	rr(t_stack *a, t_stack *b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
