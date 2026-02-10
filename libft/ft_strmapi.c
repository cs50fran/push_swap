/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:45:12 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:09:56 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*goal;

	len = ft_strlen(s);
	goal = malloc(len + 1);
	if (!goal)
		return (NULL);
	i = 0;
	while (i < len)
	{
		goal[i] = f(i, s[i]);
		i++;
	}
	goal[i] = '\0';
	return (goal);
}

/*
** strmapi() applies function f to each character of string s,
** giving its index as the first argument, to create a new string
** resulting from successive applications of f.
** Returns the new allocated string or NULL if allocation fails.
*/

/* char teste(unsigned int i, char c)
{
	if (i >= 0)
		c += 1;
	return c;
}

int main()
{
	char *str = ft_strmapi("a  bc", teste);
	printf("%s", str);
} */