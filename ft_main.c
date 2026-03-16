/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:17:25 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/03/16 10:38:16 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_list **a, t_list **b)
{
	ft_lstclear(b);
	ft_lstclear(a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(1);
	if (argc == 2)
		create_stack_split(argv[1], &stack_a);
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
	free_stacks(&stack_a, &stack_b);
}
