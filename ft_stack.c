/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:20:31 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/10 15:55:45 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_split(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-'))
			return(1);
		if ((str[i] == '+' || str[i] == '-' ) && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return(1);
		i++;
	}
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
		while(ind != NULL)
		{
			if (tmp->content == ind->content)
				return(1);
			ind = ind->next;
		}
		tmp = tmp->next;
	}
	return(0);
}

static void	free_mat(char **arr)
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


void create_stack_split(char *argv, t_list **head)
{
	char	**arr;
	int		str;
	
	arr = ft_split(argv, ' ');
	str = 0;
	while (arr[str])
	{
		if (ft_check_split(arr[str]) != 0)
		{
			free_mat(arr);
			return(ft_error(head));
		}	
		if (*head == NULL)
			*head = ft_lstnew(ft_atoi(arr[str]));
		else
			ft_lstadd_back(head, ft_lstnew(ft_atoi(arr[str])));
		str++;
	}
	if (ft_check_stack(head) != 0)
	{
		free_mat(arr);
		ft_error(head);
	}
	free_mat(arr);
}

void create_stack(char **av, int ac, t_list **head)
{
	int	i;
	
	i = 1;
	while (i < ac)
	{
		if (*head == NULL)
			*head = ft_lstnew(ft_atoi(av[i]));
		else
			ft_lstadd_back(head, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	if (ft_check_stack(head) != 0)
	{
		ft_lstclear(head);
		ft_error(head);
	}
}