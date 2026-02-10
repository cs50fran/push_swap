/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:52:58 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:06:30 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/* Erases the data in the n bytes of the memory 
starting at the location pointed to by s, 
by writing zeros (bytes containing '\0') to that area. */
/* int main()
{
	char str[] = "ach que nao vai dar";
	ft_bzero(str, 5);
	printf("%s", str);
} */
