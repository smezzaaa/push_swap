/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:33:32 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:25:47 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_highest(t_list **head)
{
	t_list	*lst;
	t_list	*tmp;

	lst = (*head)->next;
	tmp = *head;
	while (lst)
	{
		if ((tmp->content) < (lst->content))
		{
			tmp = lst;
			lst = tmp->next;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}

void	ft_sort_two(t_list	**head_a)
{
	if (*head_a == ft_highest(head_a))
		sa(head_a);
	else
		return ;
}

void	ft_sort_three(t_list **head_a)
{
	t_list	*highest;

	highest = ft_highest(head_a);
	if (*head_a == highest)
		ra(head_a);
	else if ((*head_a)->next == highest)
		rra(head_a);
	if ((*head_a)->content > (*head_a)->next->content)
		sa(head_a);
}

void	ft_sort_four(t_list **head_a, t_list **head_b)
{
	if (ft_check_order(head_a) == 1)
		return ;
	while (*head_a)
	{
		if ((*head_a)->content == 0)
		{
			pb(head_a, head_b);
			break ;
		}
		else
			ra(head_a);
	}
	if (*head_b != ft_highest(head_b))
		sb(head_b);
	ft_sort_three(head_a);
	pa(head_a, head_b);
}

void	ft_sort_five(t_list **head_a, t_list **head_b)
{
	int	i;

	i = 0;
	if (ft_check_order(head_a) == 1)
		return ;
	while (i <= 1)
	{
		if ((*head_a)->content < 2)
		{
			pb(head_a, head_b);
			i++;
		}
		else
			ra(head_a);
	}
	if (*head_b != ft_highest(head_b))
		sb(head_b);
	ft_sort_three(head_a);
	pa(head_a, head_b);
	pa(head_a, head_b);
}
