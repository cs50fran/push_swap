/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:09:13 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/05 19:12:59 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			total;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	total = size * nmemb;
	arr = malloc(total);
	if (!arr)
		return (NULL);
	ft_bzero(arr, total);
	return (arr);
}

/* int main(void)
{
	size_t	count = 5;
	size_t	size = sizeof(int);

	// Test 1: normal allocation
	int *arr_ft = ft_calloc(0, 0);
	int *arr_std = calloc(0, 0);

	if (!arr_ft || !arr_std)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	if (memcmp(arr_ft, arr_std, count * size) == 0)
		printf("Memory blocks are identical\n");
	else
		printf("Memory blocks differ\n");
	free(arr_ft);
	free(arr_std);
	return 0;
} */

/*The calloc() function allocates memory for an array 
of nmemb elements of size  bytes  each
and  returns  a  pointer to the allocated memory.*/

/*
The memory is set to zero.  
If nmemb or size is 0, then calloc() returns either NULL, 
or a unique pointer value that can later be
successfully  passed  to  free().
*/

/*
If the multiplication of nmemb and size would result in
integer overflow, then calloc() returns an error.  
By contrast, an integer overflow  would
not  be  detected  in  the following call to malloc(), 
with the result that an incorrectly
sized block of memory would be allocated: 
*/
