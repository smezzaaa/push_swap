/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:52:49 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:32:52 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunk(t_list **head_a, t_list **head_b)
{
	int	n_chunk;
	int	s_chunk;
	int	i;

	if (ft_lstsize(head_a) <= 100)
		n_chunk = 4;
	else
		n_chunk = 10;
	s_chunk = ft_lstsize(head_a) / n_chunk;
	i = 2;
	while (ft_lstsize(head_a) > 2)
	{
		if (ft_lstsize(head_b) == (s_chunk * i))
			i += 2;
		if ((*head_a)->content < (s_chunk * (i - 1)))
		{
			pb(head_a, head_b);
			rb(head_b);
		}
		else if ((*head_a)->content < (s_chunk * i))
			pb(head_a, head_b);
		else
			ra(head_a);
	}
	ft_sort_two(head_a);
}

void	ft_target_node(t_list **head_a, t_list **head_b)
{
	t_list	*target;
	t_list	*current_a;
	t_list	*current_b;

	current_b = *head_b;
	while (current_b)
	{
		target = NULL;
		current_a = *head_a;
		while (current_a)
		{
			if (current_b->content < current_a->content)
			{
				if (!target || current_a->content < target->content)
					target = current_a;
			}
			current_a = current_a->next;
		}
		if (!target)
			target = ft_smallest(head_a);
		current_b->target_node = target;
		current_b = current_b->next;
	}
}
