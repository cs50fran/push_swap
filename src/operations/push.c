/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 16:35:27 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push: Take the first element at the top of a and put it at the top of b
*/
void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop(b);
	if (node)
		stack_push(a, node);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop(a);
	if (node)
		stack_push(b, node);
	ft_putstr_fd("pb\n", 1);
}
