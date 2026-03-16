/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:34:26 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:19:32 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;
	t_list	*new;

	new = ft_lstnew((*src)->content);
	new->next = *dest;
	*dest = new;
	tmp = (*src)->next;
	ft_lstdelone(src);
	*src = tmp;
}

int	pa(t_list **head_a, t_list **head_b)
{
	ft_push(head_a, head_b);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_list **head_a, t_list **head_b)
{
	ft_push(head_b, head_a);
	write(1, "pb\n", 3);
	return (1);
}
