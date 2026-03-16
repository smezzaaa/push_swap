/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:42:05 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:34:40 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost(t_list **head, t_list *curr)
{
	int	len;
	int	pos;
	int	cost;

	len = ft_lstsize(head);
	pos = ft_find_pos(head, curr);
	cost = 0;
	if (pos > (len / 2))
		cost = (len - pos);
	else if (pos <= (len / 2))
		cost = pos;
	return (cost);
}

t_list	*ft_smallest(t_list **head)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *head;
	tmp = *head;
	while (lst)
	{
		if ((lst->content) < (tmp->content))
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

int	ft_find_pos(t_list **head, t_list *curr)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	while (tmp && tmp != curr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*ft_cheapest(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest;
	t_list	*tmp;
	int		cost;
	int		pos;

	tmp = *head_b;
	cost = -1;
	pos = 0;
	while (*head_b)
	{
		if (cost > ft_calc(head_a, &tmp, *head_b, (*head_b)->target_node)
			|| cost == -1)
		{
			cost = ft_calc(head_a, &tmp, *head_b, (*head_b)->target_node);
			cheapest = *head_b;
		}
		*head_b = (*head_b)->next;
	}
	*head_b = tmp;
	return (cheapest);
}

int	ft_calc(t_list **a, t_list **b, t_list *curr, t_list *trg)
{
	int	pos_t;
	int	pos_b;
	int	mid_t;
	int	mid_b;
	int	cost;

	pos_t = ft_find_pos(a, trg);
	pos_b = ft_find_pos(b, curr);
	mid_t = ft_lstsize(a) / 2;
	mid_b = ft_lstsize(b) / 2;
	if ((pos_t <= mid_t && pos_b <= mid_b)
		|| (pos_t > mid_t && pos_b > mid_b))
	{
		if (ft_cost(b, curr) > ft_cost(a, trg))
			cost = ft_cost(b, curr);
		else
			cost = ft_cost(a, trg);
	}
	else
		cost = ft_cost(b, curr) + ft_cost(a, trg);
	return (cost);
}
