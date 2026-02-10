/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:39:06 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:09:31 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joined;
	size_t		t_len;
	int			i;
	int			j;

	t_len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(t_len + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

// Allocates memory using malloc(3)) and returns new string
// the result of concatenating ’s1’ and ’s2’.
/* int main()
{
	char *teste = ft_strjoin("sera que ", "isto funciona");
	printf("%s", teste);
	free(teste);
} */