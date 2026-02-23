/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:30:27 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/23 19:59:26 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstindex(int *arr, int size, t_list **head)
{
	int	i;
	t_list	*tmp;

	tmp = *head;
	while (*head)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == (*head)->content)
			{
				(*head)->content = i;
				i = size;	
			}
			i++;
		}
		*head = (*head)->next;
	}
	*head = tmp;
}

static void	ft_sortarr(int **arr, int size)
{
	int	i;
	int tmp;

	i = 0;
	while (i < (size - 1))
	{
		if ((*arr)[i] > (*arr)[i + 1])
		{
			tmp = (*arr)[i];
			(*arr)[i] = (*arr)[i + 1];
			(*arr)[i + 1] = tmp;

			i = 0;
		}
		else
			i++;
	}
}

void	ft_index(t_list **head)
{
	int	*arr;
	int	size;
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	size = ft_lstsize(*head);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return ;
	while (i < size)
	{
		arr[i] = (*head)->content; 
		i++;
		*head = (*head)->next;
	}
	ft_sortarr(&arr, size);
	*head = tmp;
	ft_lstindex(arr, size, head);
}
