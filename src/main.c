/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/02/08 18:29:45 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Dispatch to the appropriate sorting function based on stack size
*/
void	sort_stack(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		turk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
	{
		error_exit(a, b);
		return (1);
	}
	if (!parse_args(argc, argv, a))
		error_exit(a, b);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
