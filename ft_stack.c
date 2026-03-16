/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:20:31 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:47:10 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = new;
		}
	}
}

void	create_stack_split(char *argv, t_list **head)
{
	char	**arr;
	int		str;

	arr = ft_split(argv, ' ');
	str = 0;
	while (arr[str])
	{
		if (ft_check_split(arr[str]) != 0 || ft_check_atoi(arr[str]) != 0)
		{
			free_arr(arr);
			return (ft_error(head));
		}
		if (*head == NULL)
			*head = ft_lstnew(ft_atoi(arr[str]));
		else
			ft_lstadd_back(head, ft_lstnew(ft_atoi(arr[str])));
		str++;
	}
	if (ft_check_stack(head) != 0)
	{
		free_arr(arr);
		ft_error(head);
	}
	free_arr(arr);
}

void	create_stack(char **av, int ac, t_list **head)
{
	int	i;
	int	n;

	i = 1;
	while (i < ac)
	{
		if (ft_check_atoi(av[i]) != 0)
		{
			ft_lstclear(head);
			ft_error(head);
		}
		n = ft_atoi(av[i]);
		if (*head == NULL)
			*head = ft_lstnew(n);
		else
			ft_lstadd_back(head, ft_lstnew(n));
		i++;
	}
	if (ft_check_stack(head) != 0)
	{
		ft_lstclear(head);
		ft_error(head);
	}
}
