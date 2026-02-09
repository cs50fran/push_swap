/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/09 15:45:53 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Free all nodes in a stack and the stack itself
*/
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!stack)
		return ;
	if (stack->top)
	{
		current = stack->top;
		i = 0;
		while (i < stack->size)
		{
			next = current->next;
			free(current);
			current = next;
			i++;
		}
	}
	free(stack);
}

/*
** Free a split array (array of strings from ft_split)
*/
void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/*
** Print error message to stderr and exit
** Free stacks before exiting
*/
void	error_exit(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}
