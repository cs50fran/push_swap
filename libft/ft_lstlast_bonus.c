/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:01:53 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/03 19:50:02 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
int main()
{
	t_list *head;
	t_list *node_a;
	t_list *node_b;
	t_list *node_c;
	t_list *node_d;
	t_list *node_z;
	
	node_a = ft_lstnew("One");
	if (!node_a)
		return (1);
	
	// Node A is now the start of the list.
	head = node_a; 
	node_b = ft_lstnew("Two");
	if (!node_b)
	{
		free(node_a);
		return (1); 
	}
	node_a->next = node_b; 
	node_c = ft_lstnew("Three");
	if (!node_c)
	{
		free(node_a);
		free(node_b);
		return (1);
	}
	node_b->next = node_c;
	
	node_d = ft_lstnew("Four");
	if(!node_d)
	{
		free(node_a);
		free(node_b);
		free(node_c);
		return (1);
	}
	node_c->next = node_d;

	node_z = ft_lstnew("Passou a fila");
	ft_lstadd_front(&head, node_z);

	printf("Last node content: %s\n", (char *)ft_lstlast(head)->content);

	t_list *current = head;
	// --- Verification (Traversing the List) ---
	printf("--- List Contents ---\n");
	while (current != NULL)
	{
		printf("Content: %s\n", (char *)current->content);
		printf("Size of Node: %d\n", ft_lstsize(current));
		current = current->next; // Move to the next node
	}
	ft_lstclear(head, del);
	return (0);
}
*/