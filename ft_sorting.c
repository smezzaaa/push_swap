/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:52:49 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/12 15:01:08 by smeza-ro         ###   ########.fr       */
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
	if (len <= 100)
		n_chunk = 4;
	else
		n_chunk = 10;
	s_chunk = len / n_chunk;
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
/* 
void	ft_target_node(t_list **head_a, t_list **head_b)
{
	t_list	*target;
	t_list	*tmp_a;
	t_list	*tmp_b;
	long	match;

	tmp_a = *head_a;
	tmp_b = *head_b;
	while (*head_b)
	{
		match = LONG_MAX;
		*head_a = tmp_a;
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
			target = ft_smallest(&tmp_a);
		(*head_b)->target_node = target;
		*head_b = (*head_b)->next;
	}
	*head_a = tmp_a;
	*head_b = tmp_b;
} */

void ft_target_node(t_list **head_a, t_list **head_b)
{
    t_list  *target;
    t_list  *current_a;
    t_list  *current_b;

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
		{
			//printf("top of B = %d\n", (current_b->content));	
            target = ft_smallest(head_a);
			//printf("target content = %d\n", (target->content));	
			
		}
        current_b->target_node = target;
        current_b = current_b->next;
    }
}