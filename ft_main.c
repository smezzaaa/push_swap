/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:17:25 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/10 19:49:09 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ac_av_check(int ac, char **av, t_list **head)
{
	int	i;

	i = 1;
	if (ac < 2)
		exit(1);
	while (i < ac)
	{
		if (ft_check_split(av[i]) == 1)
			return (ft_error(head));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	ft_ac_av_check(argc, argv, &stack_a);
	if (argc == 2)
		create_stack_split(argv[2], &stack_a);
	else if (argc > 2)
		create_stack(argv, argc, &stack_a);
	if (!stack_a)
		return (ft_lstclear(&stack_a), 0);
	ft_index(&stack_a);
	if (ft_lstsize(&stack_a) == 2)
		ft_sort_two(&stack_a);
	else if (ft_lstsize(&stack_a) == 3)
		ft_sort_three(&stack_a);
	else if (ft_lstsize(&stack_a) == 4)
		ft_sort_four(&stack_a, &stack_b);
	else if (ft_lstsize(&stack_a) == 5)
		ft_sort_five(&stack_a, &stack_b);
	else if (ft_lstsize(&stack_a) > 5)
		ft_push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_b);
	ft_lstclear(&stack_a);
}
