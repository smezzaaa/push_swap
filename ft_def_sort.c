/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:33:32 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/25 12:25:44 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **head_a, t_list **head_b)
{
	t_list	*tmp = *head_a;

	ft_index(head_a);
	while(tmp)
	{
		if ((tmp)->content > 2)
			pb(&tmp, head_b);
		tmp = (tmp)->next;
	}
	while (*head_a)
	{
		if((*head_a)->content == 2)
		ra(head_a);
		if((*head_a)->content == 1)
		sa(head_a);
		if((*head_a)->content == 0)
		{
			tmp = *head_a;
			*head_a = (*head_a)->next;
			if((*head_a)->content == 2)
				sa(head_a);
			break;
		}
	}
		*head_a = tmp;
}

void	ft_sort_five(t_list **head_a, t_list ** head_b)
{
	t_list	*tmp;
	
	ft_sort_three(head_a, head_b);
	while (*head_b)
	{
		if ((*head_b)->content == 4 && (*head_b)->next != NULL)
			sb(head_b);
		pa(head_a, head_b);
		ra(head_a);
	}
}