/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:34:17 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:10:36 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_copy_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	copy_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		copy_len = 0;
	else
		copy_len = s_len - start;
	if (len < copy_len)
		copy_len = len;
	return (copy_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	copy_len;

	copy_len = ft_copy_len(s, start, len);
	sub = malloc(copy_len + 1);
	if (!sub)
		return (NULL);
	if (copy_len == 0)
	{
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while (i < copy_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
** ft_substr() allocates and returns a substring from the string s.
** The substring begins at index start and is of maximum length len.
** Returns the new string, or NULL if the allocation fails.
*/
/* int main()
{
	char *teste = ft_substr("vamos la ver isto", 5, 18446744073709551615);
	printf("%s", teste);
	free(teste);
} */
