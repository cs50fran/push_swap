/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:15:41 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:11 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

//Adds the node ’new’ at the end of the list.
/*
int main()
{
	t_list *head;
    t_list *node_a;
    t_list *node_b;
	t_list *node_que_passa_a_fila;
	t_list *node_last;
	
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

	node_que_passa_a_fila = ft_lstnew("Passou a fila");
	if (!node_que_passa_a_fila)
	{
		free(node_a);
		free(node_b);
		return (1); 
	}
	node_last = ft_lstnew("Inserido no fim");
	if (!node_que_passa_a_fila)
	{
		free(node_a);
		free(node_b);
		free(node_que_passa_a_fila);
		return (1); 
	}

	ft_lstadd_front(&head, node_que_passa_a_fila);
	ft_lstadd_back(&head, node_last);

	printf("Size of List: %d\n", ft_lstsize(head));
	printf("Last node content: %s\n", (char *)ft_lstlast(head)->content);
	
    t_list *current = head;
    // --- Verification (Traversing the List) ---
    printf("--- List Contents ---\n");
    while (current != NULL)
    {
        printf("Content: %s\n", (char *)current->content);
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