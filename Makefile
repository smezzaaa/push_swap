# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 09:50:51 by smeza-ro          #+#    #+#              #
#    Updated: 2026/03/10 15:50:08 by smeza-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRCS = ft_atoi.c ft_lst.c ft_split.c ft_stack.c ft_push.c \
		ft_rev_rotate.c ft_rotate.c ft_swap.c ft_cost.c ft_index.c \
		ft_move.c ft_push_swap.c ft_sorting.c ft_tiny_sort.c ft_main.c\

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re