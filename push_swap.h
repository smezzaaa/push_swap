/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:56:05 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/02/17 15:16:52 by smeza-ro         ###   ########.fr       */
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
void	create_stack(char *argv);
void	ft_error(char **arr);
int		ft_check_split(char	*str);
int		ft_check_stack(t_list **head);

#endif