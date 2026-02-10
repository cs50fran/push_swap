/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:33:25 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/03 19:20:09 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(long int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		len;
	char		*goal;

	nb = n;
	if (n < 0)
		nb *= -1;
	len = ft_num_len(n);
	goal = malloc ((len + 1) * sizeof(char));
	if (!goal)
		return (NULL);
	goal[len] = '\0';
	if (n == 0)
	{
		goal[0] = '0';
		return (goal);
	}
	if (n < 0)
		goal[0] = '-';
	while (nb > 0)
	{
		goal[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (goal);
}

/* int main()
{
	printf("%lu\n", ft_num_len(0));
	char *num1 = ft_itoa(2147483647);
	char *num2 = ft_itoa(-2147483648);
	char *num3 = ft_itoa(0);
	char *num4 = ft_itoa(-42);
	char *num5 = ft_itoa(-42);
	printf ("ft_itoa output: %s\n", num1);
	printf ("ft_itoa output: %s\n", num2);
	printf ("ft_itoa output: %s\n", num3);
	printf ("ft_itoa output: %s\n", num4);
	printf ("ft_itoa output: %s\n", num5);
} */

// Converts int to char