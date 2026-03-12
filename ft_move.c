/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:12:27 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/12 15:17:08 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_move(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	int	pos_t;
	int	pos_b;
	int	mid_a;
	int	mid_b;

	pos_t = ft_find_pos(head_a, cheapest->target_node);
	pos_b = ft_find_pos(head_b,cheapest);
	mid_a = ft_lstsize(head_a) / 2;
	mid_b = ft_lstsize(head_b) / 2;
	// printf("pos_t = %d\n", pos_t);
	// printf("pos_b = %d\n", pos_b);

	if (pos_t <= mid_a && pos_b <= mid_b)
		ft_execute_rotate(head_a, head_b, cheapest);
	else if (pos_t > mid_a && pos_b > mid_b)
		ft_execute_rev_rotate(head_a, head_b, cheapest);
	else if (pos_t > mid_a && pos_b <= mid_b)
		ft_execute_cross_ba(head_a, head_b, cheapest);
	else if (pos_t <= mid_a	&& pos_b > mid_b)
		ft_execute_cross_ab(head_a, head_b, cheapest);
}
	
void	ft_execute_rotate(t_list **head_a, t_list **head_b, t_list *cheapest)
{
int	cost_a;
int	cost_b;
int i;

cost_a = ft_cost(head_a, cheapest->target_node);
cost_b = ft_cost(head_b, cheapest);
// printf("cost a = %d\n", cost_a);
// printf("cost b = %d\n", cost_b);

i = cost_a;
if (cost_b < cost_a)
	i = cost_b;
while (i > 0)
{
	rr(head_a, head_b);
	i--;
}
if (cost_b < cost_a)
{
	while ((cost_a - cost_b) > 0)
	{
		ra(head_a);
		cost_a--;
	}
}
else if (cost_a < cost_b)
{
	while ((cost_b - cost_a) > 0)
	{
		rb(head_b);
		cost_b--;
	}
}
}

void	ft_execute_rev_rotate(t_list **head_a, t_list **head_b, t_list *cheapest)
{
	int	cost_a;
	int	cost_b;
	int i;

	cost_a = ft_cost(head_a, cheapest->target_node);
	cost_b = ft_cost(head_b, cheapest);
	i = cost_a;
	if (cost_b < cost_a)
		i = cost_b;
	while (i > 0)
	{
		rrr(head_a, head_b);
		i--;
	}
	if (cost_b < cost_a)
	{
		while ((cost_a - cost_b) > 0)
		{
			rra(head_a);
			cost_a--;
		}
	}
	else if (cost_a < cost_b)
	{
		while ((cost_b - cost_a) > 0)
		{
			rrb(head_b);
			cost_b--;
		}
	}
}

void	ft_execute_cross_ba(t_list **head_a, t_list **head_b, t_list *curr)
{
	int	cost_b;
	int	cost_a;

	cost_b = ft_cost(head_b, curr);
	cost_a = ft_cost(head_a, curr->target_node);
	while(cost_b > 0)
	{
		rb(head_b);
		cost_b--;
	}
	while(cost_a > 0)
	{
		rra(head_a);
		cost_a--;
	}
}

void	ft_execute_cross_ab(t_list **head_a, t_list **head_b, t_list *curr)
{
	int	cost_b;
	int	cost_a;

	cost_a = ft_cost(head_a, curr->target_node);
	cost_b = ft_cost(head_b, curr);
	// printf("curr = %d\n", curr->content);
	// printf("cost_a = %d\n", cost_a);
	// printf("cost_b = %d\n", cost_b);

	while(cost_a > 0)
	{
		ra(head_a);
		cost_a--;
	}
	while(cost_b > 0)
	{
		rrb(head_b);
		cost_b--;
	}
}