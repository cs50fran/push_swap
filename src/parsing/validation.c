/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/01 19:38:57 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if a string is a valid integer and store the value
** Handles: sign, digits only, INT_MIN to INT_MAX range
*/
int	is_valid_integer(char *str, long *num)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	*num = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		*num = *num * 10 + (str[i] - '0');
		i++;
	}
	*num *= sign;
	return (*num >= INT_MIN && *num <= INT_MAX);
}

/*
** Check if a value already exists in the stack (duplicate check)
*/
int	has_duplicates(t_stack *stack, int value)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
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
