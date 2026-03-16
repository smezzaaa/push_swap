/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:21:43 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 09:41:10 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;
	t_list	*target;

	if (ft_check_order(head_a) == 1)
		return ;
	ft_chunk(head_a, head_b);
	while (*head_b)
	{
		ft_target_node(head_a, head_b);
		cheapest = ft_cheapest (head_a, head_b);
		target = cheapest->target_node;
		ft_move(head_a, head_b, cheapest);
		pa(head_a, head_b);
	}
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
	while ((*head_a)->content > smallest->content)
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
	t_list	*next;

	tmp = *head_a;
	next = tmp->next;
	while (tmp && tmp->next)
	{
		if (tmp->content > next->content)
			return (0);
		next = next->next;
		tmp = tmp->next;
	}
	return (1);
}
/* 
void	printlst(t_list *ptr)
{
	while (ptr != NULL)
	{
		if ((ptr)->next != NULL)
			printf ("|%d|->", (ptr)->content);
		else
			printf ("|%d|\n", (ptr)->content);
		ptr = (ptr)->next;
	}
} */