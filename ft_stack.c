/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:20:31 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/17 15:21:48 by smeza-ro         ###   ########.fr       */
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

void	ft_error(char **arr)
{
	free_mat(arr);
	write(1, "Error\n", 6);
	exit(1);
}

static void	printlst(t_list *ptr)
{
	while (ptr != NULL)
	{
		if (ptr->next != NULL)
			printf ("|%d|->", ptr->content);
		else
			printf ("|%d|\n", ptr->content);
		ptr = ptr->next;
	}
}

void create_stack(char *argv)
{
	char	**arr;
	int		str;
	int		n;
	t_list	*head;
	
	arr = ft_split(argv, ' ');
	str = 0;
	head = NULL;
	while (arr[str])
	{
		if (ft_check_split(arr[str]) != 0)
			return(ft_error(arr));
		n = ft_atoi(arr[str]);
		if (head == NULL)
			head = ft_lstnew(n);
		else
			ft_lstadd_back(&head, ft_lstnew(n));
		str++;
	}
	if (ft_check_stack(&head) != 0)
	{
		ft_lstclear(&head);
		ft_error(arr);
	}
	free_mat(arr);
	printlst(head);
}

int main()
{
	create_stack("2 4 3 37 6");
}
/* 
int main()
{
	t_list	*head;
	t_list	*nodo1 = NULL;
	t_list	*nodo2 = NULL;
	t_list	*nodo3 = NULL;

	nodo1 = malloc(sizeof(t_list));
	nodo2 = malloc(sizeof(t_list));
	nodo3 = malloc(sizeof(t_list));

	nodo1->content = "bop";
	nodo2->content = "bip";
	nodo3->content = "bup";

	nodo1->next = nodo2;
	nodo2->next = nodo3;
	nodo3->next = NULL;
	head = nodo1;

	printlst (head);
	printlst (ft_lstlast(head));
	free(nodo1);
	free(nodo2);
	free(nodo3);
} */