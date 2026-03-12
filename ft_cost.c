/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:42:05 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/12 15:16:50 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_cost(t_list **head, t_list *curr)
{
	int	len;
	int pos;
	int cost;
	
	len = ft_lstsize(head);
	pos = ft_find_pos(head, curr);
	cost = 0;
	if (pos > (len / 2))
		cost = (len - pos);
	else if (pos <= (len / 2))
		cost = pos;
	return (cost);
}


t_list *ft_smallest(t_list **head)
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
		if (cost > ft_calculate(head_a, head_b, (*head_b)->target_node) || cost == -1)
		{
			cost = ft_calculate(head_a, head_b, (*head_b)->target_node);
			cheapest = *head_b;
			pos = ft_find_pos(&tmp, cheapest);
		}
		*head_b = (*head_b)->next;	
	}
	*head_b = tmp;
	return (cheapest);
}

int ft_calculate(t_list **head_a, t_list **head_b, t_list *target)
{
	int	pos_t;
	int pos_b;
	int cost;

	pos_t = ft_find_pos(head_a, target);
	pos_b = ft_find_pos(head_b, *head_b);
	if ((pos_t <= (ft_lstsize(head_a) / 2)
		&& pos_b < (ft_lstsize(head_b) / 2))
		|| (pos_t >= (ft_lstsize(head_a) / 2) && pos_b > (ft_lstsize(head_b) / 2)))
	{
		if (ft_cost(head_b, *head_b) > ft_cost(head_a, target))
			cost = ft_cost(head_b, *head_b);
		else
			cost = ft_cost(head_a, target);
	}
	else if (pos_t == pos_b)
		cost = ft_cost(head_a, target);
	else
		cost = ft_cost(head_b, *head_b) + ft_cost(head_a, target);
	return (cost);
}