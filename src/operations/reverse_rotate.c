/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 12:00:04 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Reverse rotate: Shift down all elements by 1. Last becomes first.
** With circular doubly-linked list, just move top pointer to prev
*/
static void	reverse_rotate(t_stack *stack)
{
	if (!stack || !stack->top || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

/*
** rra: Reverse rotate stack a - last element becomes first
*/
void	rra(t_stack *a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/*
** rrb: Reverse rotate stack b - last element becomes first
*/
void	rrb(t_stack *b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/*
** rrr: rra and rrb at the same time
*/
void	rrr(t_stack *a, t_stack *b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
