/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 15:15:02 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if the stack is sorted in ascending order (smallest at top)
*/
int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top || stack->size <= 1)
		return (1);
	current = stack->top;
	i = 0;
	while (i < stack->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

/*
** Get the node with the minimum value in the stack
*/
t_node	*stack_get_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;
	int		i;

	if (!stack || !stack->top)
		return (NULL);
	min = stack->top;
	current = stack->top->next;
	i = 1;
	while (i < stack->size)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
		i++;
	}
	return (min);
}

/*
** Get the node with the maximum value in the stack
*/
t_node	*stack_get_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max;
	int		i;

	if (!stack || !stack->top)
		return (NULL);
	max = stack->top;
	current = stack->top->next;
	i = 1;
	while (i < stack->size)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
		i++;
	}
	return (max);
}

/*
** Get the position of a node in the stack (0 = top)
*/
int	get_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->top || !node)
		return (-1);
	current = stack->top;
	pos = 0;
	while (pos < stack->size)
	{
		if (current == node)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

/*
** Pop and return the top node from the stack
*/
t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
	}
	else
	{
		stack->top = node->next;
		stack->top->prev = node->prev;
		node->prev->next = stack->top;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
