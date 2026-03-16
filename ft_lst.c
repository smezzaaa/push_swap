/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:27:43 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:18:21 by smeza-ro         ###   ########.fr       */
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
	lst->target_node = NULL;
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

void	ft_lstdelone(t_list **lst)
{
	if (!lst)
		return ;
	free (*lst);
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

int	ft_lstsize(t_list **lst)
{
	int		size;
	t_list	*tmp;

	tmp = *lst;
	size = 0;
	while (*lst != NULL)
	{
		*lst = (*lst)->next;
		size++;
	}
	*lst = tmp;
	return (size);
}
