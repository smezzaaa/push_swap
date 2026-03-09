/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:52:49 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/08 18:52:24 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunk(t_list **head_a, t_list **head_b)
{
	int	len;
	int	n_chunk;
	int s_chunk;
	int	i;

	len = ft_lstsize(head_a);
	n_chunk = len / 50;
	s_chunk = len / n_chunk;
	i = 1;
	while (len >= 3)
	{
		if ((*head_a)->content < (s_chunk * i))
		{
			pb(head_a, head_b);
			len = ft_lstsize(head_a);
			if (len <= (s_chunk * (n_chunk - i)))
				i++;
		}
		else
			ra(head_a);
	}
	ft_sort_three(head_a);
}

void	ft_target_node(t_list **head_a, t_list **head_b)
{
	t_list	*target;
	long	match;

	while (*head_b)
	{
		match = LONG_MAX;
		while (*head_a)
		{
			if ((*head_b)->content < (*head_a)->content
				&& (*head_a)->content < match)
			{
				match = (*head_a)->content;
				target = *head_a;
			}
			*head_a = (*head_a)->next;
		}
		if (match == LONG_MAX)
			target = ft_smallest(head_a);
		else
			(*head_b)->target_node = target;
	}
}
