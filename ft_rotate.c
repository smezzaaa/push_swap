/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:32:47 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:20:04 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **head)
{
	t_list	*top;
	t_list	*last;
	t_list	*tmp;

	top = *head;
	last = ft_lstnew(top->content);
	ft_lstadd_back(head, last);
	tmp = top->next;
	ft_lstdelone(head);
	*head = tmp;
}

int	ra(t_list **head_a)
{
	ft_rotate(head_a);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_list **head_b)
{
	ft_rotate(head_b);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_list **head_a, t_list **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	write(1, "rr\n", 3);
	return (1);
}
