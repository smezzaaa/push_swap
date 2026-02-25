/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:56:05 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/25 11:43:42 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdint.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *neww);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	create_stack(char *argv, t_list **head);
void	ft_error(char **arr);
int		ft_check_split(char	*str);
int		ft_check_stack(t_list **head);
void	ft_swap(t_list **head);
int		sa(t_list	**head_a);
int		sb(t_list	**head_b);
int		ss(t_list **head_a, t_list **head_b);
void	ft_push(t_list **dest, t_list **src);
int		pa(t_list **head_a, t_list **head_b);
int		pb(t_list **head_b, t_list **head_a);
void	ft_rotate(t_list **head);
int		ra(t_list **head_a);
int		rb(t_list **head_b);
int		rr(t_list **head_a, t_list **head_b);
void	ft_rev_rotate(t_list **head);
int		rra(t_list **head_a);
int		rrb(t_list **head_b);
int		rrr(t_list **head_a, t_list **head_b);
void	ft_index(t_list **head);
void	ft_sort_three(t_list **head_a, t_list **head_b);
void	ft_sort_five(t_list **head_a, t_list ** head_b);


#endif