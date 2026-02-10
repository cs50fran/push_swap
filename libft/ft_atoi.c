/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:37:58 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:06:21 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	goal;
	int	neg;

	goal = 0;
	neg = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-' )
			neg = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		goal = goal * 10 + (nptr[i] - '0');
		i++;
	}
	return (goal * neg);
}

//Converts the initial portion of the string to int.
/* int main()
{
	char *input = "\010 8";
	int a = ft_atoi(input);
	int b = atoi(input);
	printf("ft_atoi: %d\n", a);
	printf("atoi: %d\n", b); 
	} */
