/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:13:57 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/23 10:57:35 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **head)
{
	t_list	*last;
	t_list	*top;
	t_list	*sec_last;

	last = ft_lstlast(*head);
	top = ft_lstnew(last->content);
	sec_last = *head;
	while(sec_last->next != last)
		sec_last = sec_last->next;
	top->next = *head;
	*head = top;
	sec_last->next = NULL;
	ft_lstdelone(&last);
}

int	rra(t_list **head_a)
{
	ft_rev_rotate(head_a);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **head_b)
{
	ft_rev_rotate(head_b);
	write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_list **head_a, t_list **head_b)
{
	ft_rev_rotate(head_a);
	ft_rev_rotate(head_b);
	write(1, "rrr\n", 4);
	return (1);
}