/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:14:38 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:09:43 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	return (len);
}

/*
** strlcpy() copies up to size - 1 characters from the NUL-terminated string src
** to dst, NUL-terminating the result if size is not 0.
** Returns the total length of src.
*/
/* #include <stdio.h>
int main()
{
	char *input = "Hello world";
	char teste[12];
	char orig[12];
	int a = ft_strlcpy(teste, input, 1);
	int b = strlcpy(orig, input, 1);
	
	printf("ft_strlcpy return -> %d\n", a);
	printf("strlcpy return -> %d\n", b);
	printf("%s\n", teste);
	printf("%s\n", orig);
} */
