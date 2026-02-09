/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 12:19:27 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Add a number to the bottom of the stack (to maintain argument order)
*/
static int	add_to_stack_bottom(t_stack *stack, int value)
{
	t_node	*node;

	if (has_duplicates(stack, value))
		return (0);
	node = node_new(value);
	if (!node)
		return (0);
	if (stack->top == NULL)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
		stack->size++;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->size++;
	}
	return (1);
}

/*
** Parse a single string that may contain multiple numbers (space-separated)
*/
static int	parse_string(char *str, t_stack *stack)
{
	char	**split;
	long	num;
	int		i;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_integer(split[i], &num))
		{
			free_split(split);
			return (0);
		}
		if (!add_to_stack_bottom(stack, (int)num))
		{
			free_split(split);
			return (0);
		}
		i++;
	}
	free_split(split);
	return (1);
}

/*
** Parse all command line arguments and build stack a
** Returns 1 on success, 0 on error
*/
int	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		if (!parse_string(argv[i], a))
			return (0);
		i++;
	}
	if (a->size == 0)
		return (0);
	assign_indices(a);
	return (1);
}
