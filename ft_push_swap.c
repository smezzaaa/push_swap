/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:21:43 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/09 20:25:31 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;

	if (ft_check_order(head_a) != 0)
		return ;
	ft_chunk(head_a, head_b);
	ft_target_node(head_a, head_b);
	while (*head_b)
	{
		cheapest = ft_cheapest (head_a, head_b);
		ft_move(head_a, head_b, cheapest);
		pa(head_a, head_a);
		*head_b = (*head_b)->next;
	}
	if (*head_a != ft_smallest(head_a))
		ft_tidy(head_a, ft_smallest(head_a));
	ft_lstclear(head_b);
}

void	ft_tidy(t_list **head_a, t_list *smallest)
{
	t_list	*tmp;
	int		pos;
	int		len;
	
	tmp = *head_a;
	pos = ft_find_pos(head_a, smallest);
	len = ft_lstsize(head_a);
	while (*head_a != smallest)
	{
		if (pos <= len / 2)
			ra(head_a);
		else
			rra(head_a);
	}
}

int	ft_check_order(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	while (*head_a)
	{
		if ((*head_a)->content < (*head_a)->next->content)
			return (0);
		*head_a = (*head_a)->next;
	}
	return (1);
}