/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 15:15:02 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initialize an empty stack
*/
t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

/*
** Create a new node with the given value
** Initializes all Turk algorithm fields to default values
*/
t_node	*node_new(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->total_cost = 0;
	node->above_median = 0;
	node->cheapest = 0;
	node->target = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*
** Push a node to the top of the stack
*/
void	stack_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

/*
** Count how many values are smaller than the given value
** This gives us the index (0 = smallest, n-1 = largest)
*/
static int	count_smaller(t_stack *stack, int value)
{
	t_node	*current;
	int		count;
	int		i;

	count = 0;
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (current->value < value)
			count++;
		current = current->next;
		i++;
	}
	return (count);
}

/*
** Assign indices to all nodes based on their relative values
** Index 0 = smallest value, index (n-1) = largest value
** This simplifies the sorting algorithm significantly
*/
void	assign_indices(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		current->index = count_smaller(stack, current->value);
		current = current->next;
		i++;
	}
}
