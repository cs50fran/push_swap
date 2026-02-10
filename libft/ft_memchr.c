/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:28:19 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:47 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*pt_s;

	pt_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pt_s[i] == (unsigned char)c)
			return ((void *)&pt_s[i]);
		i++;
	}
	return (NULL);
}

/* scans the initial n bytes of the memory area pointed to by s for the
first instance of c */
/* int main()
{
	char *ptr = (char *)ft_memchr("what we do", 't', 3);
	printf("%s", ptr);
} */
