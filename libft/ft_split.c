/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:20:11 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/05 18:36:21 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

static void	ft_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static	char	**get_words(char const *s, char c, size_t words)
{
	char		**goal;
	size_t		i;
	size_t		word_len;
	const char	*word_start;

	goal = (char **)malloc(sizeof(char *) * (words + 1));
	if (!goal)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		word_start = s;
		while (*s && *s != c)
			s++;
		word_len = s - word_start;
		goal[i] = ft_substr(word_start, 0, word_len);
		if (!goal[i++])
			return (ft_free_all(goal), NULL);
	}
	goal[i] = NULL;
	return (goal);
}

char	**ft_split(char const *s, char c)
{
	char	**goal;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	goal = get_words(s, c, words);
	if (!goal)
		return (NULL);
	return (goal);
}

/* int main()
{
	char *str = "\0aa\0bbb";
	int words = ft_count_words(str, '\0');
	printf("count_words: %d\n", words);
	char ** teste = ft_split(str, '\0');

	int i = 0;
	while(teste[i])
	{
		printf("split: %s\n", teste[i]);
		i++;
	}
	free(teste);
} */
