/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:24:19 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:08:44 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}

/* Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to
delete the content of a node if needed. */

/* void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	char	*str;
	char	*copy;
	int		i;
	
	str = (char *)content;
	copy = ft_strdup(str);
	if (!copy)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		copy[i] = ft_toupper(copy[i]);
		i++;
	}
	return ((void *)copy);
}

int main()
{
	t_list *list;
	t_list *copy_list;
	t_list *node_a;
	t_list *node_b;

	list = NULL;
	node_a = ft_lstnew("wassup ");
	if(!node_a)
		return 0;
	node_b = ft_lstnew("ma man");
	if(!node_b)
	{
		free(node_a);
		return 0;
	}
	ft_lstadd_back(&list, node_a);
	ft_lstadd_back(&list, node_b);

copy_list = ft_lstmap(list, f, del);
// ---------------- BEFORE LSTMAP ----------------	
printf("BEFORE:\n");
	while(list)
	{
		(printf("%s", (char *)list->content));
		list = list->next;
	}
printf("\n"); 
// -------------- APPLY LSTMAP -----------
printf("AFTER:\n");
	while(copy_list)
	{
		(printf("%s", (char *)copy_list->content));
		copy_list = copy_list->next;
	}
	ft_lstmap(copy_list, f, del);
	ft_lstclear(&list, del);
	ft_lstclear(&copy_list, del);
} */
