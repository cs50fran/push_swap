/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:07:30 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:14 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

//Adds the node ’new’ at the beginning of the list.
/* int main()
{
	t_list *head;
	t_list *node_a;
	t_list *node_b;
	t_list *node_c;
	
	
	node_a = malloc(sizeof(t_list));
	if (!node_a)
		return (1);

	// 3. Assign values to Node A.
	node_a->content = "One"; 
	
	// Node A is now the start of the list.
	head = node_a; 
	node_b = malloc(sizeof(t_list));
	if (!node_b)
	{
		free(node_a);
		return (1); 
	}
	node_b->content = "Two";
	node_b->next = NULL;
	node_a->next = node_b; 
	node_c = malloc(sizeof(t_list));
	if (!node_c)
	{
		free(node_a);
		free(node_b);
		return (1);
	}
	node_c->content = "Three";
	
	// 5. Link Node B to Node C.
	node_b->next = node_c;
	
	t_list *node_d;
	node_d = ft_lstnew("Four");
	if(!node_d)
	{
		free(node_a);
		free(node_b);
		free(node_c);
		return (1);
	}
	node_c->next = node_d;

	
	// --- Verification (Traversing the List) ---
	t_list *current = head;
	t_list *node_z;
	node_z = ft_lstnew("Passou a fila");
	ft_lstadd_front(&current, node_z);
	
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
} */