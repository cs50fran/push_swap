/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 12:00:48 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swap the values of the first two elements of the stack
** (We swap the content, not the nodes themselves - simpler approach)
*/
static void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	tmp_value = stack->top->value;
	tmp_index = stack->top->index;
	stack->top->value = stack->top->next->value;
	stack->top->index = stack->top->next->index;
	stack->top->next->value = tmp_value;
	stack->top->next->index = tmp_index;
}

/*
** sa: Swap the first 2 elements at the top of stack a
*/
void	sa(t_stack *a, int print)
{
	swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

/*
** sb: Swap the first 2 elements at the top of stack b
*/
void	sb(t_stack *b, int print)
{
	swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

/*
** ss: sa and sb at the same time
*/
void	ss(t_stack *a, t_stack *b, int print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
