/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 12:16:40 by fdinis-d         ###   ########.fr       */
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

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
