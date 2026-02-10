/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:39:29 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:08:55 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// Adds the node ’new’ at the beginning of the list.
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

    t_list *current = head;
    // --- Verification (Traversing the List) ---
    printf("--- List Contents ---\n");
    while (current != NULL)
    {
        printf("Content: %s\n", (char *)current->content);
		printf("Size of Node: %d\n", ft_lstsize(current));
        current = current->next; // Move to the next node
    }

    // --- Cleanup (Crucial Step without ft_lstclear) ---
    current = head;
    while (current != NULL)
    {
        t_list *next_node = current->next;
        // In this case, we only allocated strings on the stack, 
        // but if content was malloc'd, we would free(current->content);
        free(current);
        current = next_node;
    }
    return (0);
}
*/