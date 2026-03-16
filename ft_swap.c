/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:26:22 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:19:45 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **head)
{
	t_list	*fst;
	t_list	*sec;
	int		tmp;

	fst = *head;
	sec = fst->next;
	tmp = sec->content;
	sec->content = fst->content;
	fst->content = tmp;
}

int	sa(t_list	**head_a)
{
	ft_swap(head_a);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list	**head_b)
{
	ft_swap(head_b);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **head_a, t_list **head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	write(1, "ss\n", 3);
	return (1);
}
