/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 15:31:57 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** pa: Take the first element at the top of b and put it at the top of a
*/
void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop(b);
	if (node)
		stack_push(a, node);
	ft_putstr_fd("pa\n", 1);
}

/*
** pb: Take the first element at the top of a and put it at the top of b
*/
void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop(a);
	if (node)
		stack_push(b, node);
	ft_putstr_fd("pb\n", 1);
}
