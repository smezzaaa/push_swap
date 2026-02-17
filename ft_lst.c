/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:27:43 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/17 15:19:46 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = new;
		}
	}
}
void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

/* 
void	printlst(t_list *ptr)
{
	while (ptr != NULL)
	{
		if (ptr->next != NULL)
			printf ("|%s|\n", (char *)ptr->content);
		else
			printf ("|%s|\n", (char *)ptr->content);
		ptr = ptr->next;
	}
}

int main()
{
	t_list	*head;
	t_list	*nodo1 = NULL;
	t_list	*nodo2 = NULL;
	t_list	*nodo3 = NULL;

	nodo1 = malloc(sizeof(t_list));
	nodo2 = malloc(sizeof(t_list));
	nodo3 = malloc(sizeof(t_list));

	nodo1->content = "bop";
	nodo2->content = "bip";
	nodo3->content = "bup";

	nodo1->next = nodo3;
	nodo2->next = NULL;
	nodo3->next = nodo2;
	head = nodo1;

	printlst (head);
	printlst (ft_lstlast(head));
	free(nodo1);
	free(nodo2);
	free(nodo3);
} */