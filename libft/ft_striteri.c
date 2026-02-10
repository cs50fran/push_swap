/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:07:06 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:09:25 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// Applies ’f’ to each character of the s
/* void modify_char_and_print(unsigned int index, char *c)
{
	printf("Callback: Index %u, Old Char '%c'", index, *c);

	if (index % 2 == 0)
	{
		// Convert to uppercase if it is a lowercase letter
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
	else
	{
		// Convert to a star
		*c = '*';
	}
	printf(", New Char '%c'\n", *c);
} */

/* int main(void)
{
	// Test 1: Standard string
	char test_str_1[] = "Rnpu pbqrq uvag.";
	ft_striteri(test_str_1, modify_char_and_print);
	printf("Original String: %s\n", test_str_1);
	//printf("Resulting String: %s\n\n", test_str_1);

	Test 2: String with initial caps/symbols
	char test_str_2[] = "42Piscine!";
	printf("--- Test 2 ---\n");
	printf("Original String: %s\n", test_str_2);

	ft_striteri(test_str_2, modify_char_and_print);

	printf("Resulting String: %s\n\n", test_str_2);
	
	// Test 3: Edge case - empty string
	char test_str_3[] = "";
	printf("--- Test 3 ---\n");
	printf("Original String: '%s'\n", test_str_3);

	ft_striteri(test_str_3, modify_char_and_print);

	printf("Resulting String: '%s'\n\n", test_str_3);

	// Test 4: Edge case - NULL function pointer (should handle gracefully)
	char test_str_4[] = "No change";
	printf("--- Test 4 (NULL function pointer) ---\n");
	printf("Original String: %s\n", test_str_4);

	ft_striteri(test_str_4, NULL);

	printf("Resulting String: %s\n\n", test_str_4);

	return (0);
} */