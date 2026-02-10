/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdinis-d <fdinis-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:32:33 by fdinis-d          #+#    #+#             */
/*   Updated: 2025/11/06 14:07:23 by fdinis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !(*f))
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* Iterates through the list ’lst’ and applies the
function ’f’ to the content of each node. */
/* void teste(void * str)
{
	char * content = (char *) str;
	while(*content)
	{
		*content = (char)ft_toupper((int)(*content));
		content++;
	}
}

int main()
{
	t_list *head;
    t_list *node_a;
    t_list *node_b;
	t_list *node_c;
	
	node_a = ft_lstnew(ft_strdup("One"));
    if (!node_a)
		return (1);
    
    head = node_a; 
    node_b = ft_lstnew(ft_strdup("Two"));
    if (!node_b)
	{
		free(node_a);
		return (1); 
	}
    node_a->next = node_b;
	
	node_c = ft_lstnew(ft_strdup("Three"));
	if (!node_c)
	{
		free(node_a);
		free(node_b);
		return (1); 
	}
	node_b->next = node_c;

	ft_lstiter(head, teste);
	
    t_list *current = head;
    printf("--- List Contents ---\n");
    while (current != NULL)
    {
        printf("Content: %s\n", (char *)current->content);
        current = current->next; // Move to the next node
    }
    // --- Cleanup (Crucial Step without ft_lstclear) ---
	ft_lstclear(&head, teste);
    return (0);
} */