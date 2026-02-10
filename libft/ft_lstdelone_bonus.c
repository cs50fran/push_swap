/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:26:14 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:21 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// Takes a node as parameter and frees its content using the function ’del’.
// Free the node itself but does NOT free the next node.
/* void	free_content(void *content)
{
	if (content)
	{
		free(content);
		printf("freed");
	}
} */
