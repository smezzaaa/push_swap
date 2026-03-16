/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:16:01 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:50:47 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_split(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '+' || str[i] == '-'))
			return (1);
		if ((str[i] == '+' || str[i] == '-' )
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_atoi(char *av)
{
	long int	num;

	num = ft_atoi(av);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	ft_check_stack(t_list **head)
{
	t_list	*ind;
	t_list	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		ind = tmp->next;
		while (ind != NULL)
		{
			if (tmp->content == ind->content)
				return (1);
			ind = ind->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_error(t_list **head)
{
	ft_lstclear(head);
	write(2, "Error\n", 6);
	exit(1);
}
