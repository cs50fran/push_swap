/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:07:05 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:10:04 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
** strnstr() locates the first occurrence of the null-terminated string needle
** in the string haystack, searching at most len characters.
** Returns a pointer to the first occurrence in haystack,
** or NULL if needle is not found within len.
*/

/* int main()
{
	char haystack[30] = "aaabcabcd";
	char * empty = (char*)"";
	empty = ft_strnstr(haystack, "cd", 8);
	printf("%s", empty);
} */