/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:51:26 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:09:39 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// Copy/catenate a string with truncation
/* int main()
{
	char ft_dest[200];
	char dest[200];
	char *src = "CCCCCAAAAAAAAA";
	int a = ft_strlcat(dest, src, -1);
	int b = strlcat(dest, src, -1);
	printf("ft_strlcat: %d\n", a);
	printf("Original strlcat: %d\n", b);
	printf("ft_dest: %s\n", ft_dest);
	printf("dest: %s\n", dest);
} */
