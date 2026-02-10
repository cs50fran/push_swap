/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:46:12 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:18 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}

/* Deletes and frees the given node and all its successors, 
using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL. */
/* void del(void *content)
{
	free(content);
} */

/* int main()
{
	t_list *list = NULL;
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *temp;

	a = ft_lstnew(ft_strdup("alpha"));
	b = ft_lstnew(ft_strdup("beta"));
	c = ft_lstnew(ft_strdup("charlie"));

	ft_lstadd_back(&list, a);
	ft_lstadd_back(&list, b);
	ft_lstadd_back(&list, c);

	//----------------BEFORE CLEAR----------------------
	printf("---BEFORE CLEAN---\n");
	temp = list;
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&list, del);
	printf("---AFTER CLEAN---\n");
	if(!list)
		printf("List is empty, hurray!!");
	else
		printf("I dont get it");

	return 0;
} */
