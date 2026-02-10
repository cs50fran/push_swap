/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:42:47 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:51 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*one;
	const unsigned char	*two;
	size_t				i;

	one = (const unsigned char *)s1;
	two = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (one[i] != two[i])
			return (one[i] - two[i]);
		i++;
	}
	return (0);
}

// compares the first n bytes of the memory areas s1 and s2.
/* int main()
{
	char *a = "wut da hell";
	char *b = "wut da fudge";
	printf("ft_memcmp output: %d\n", ft_memcmp(a, b, 9));
} */
