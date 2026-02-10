/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:21:02 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:10:24 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	size_t	len;
	char	*goal;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1);
	while (end >= beg && ft_strchr(set, s1[end]))
		end--;
	len = end - beg + 1;
	goal = ft_substr(s1, beg, len);
	return (goal);
}

// Trims the start and end of s1 from chars in set
/* int main()
{
	char *teste;
	teste = ft_strtrim("ababaaaMy name is Simonbbaaabba", "ab");
	printf("trim: %s\n", teste);
} */