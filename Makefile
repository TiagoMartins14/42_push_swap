# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 23:48:53 by tiago             #+#    #+#              #
#    Updated: 2023/09/19 09:52:35 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs

SRCS = ft_atol.c					\
		ft_big_or_small.c			\
		ft_cheapest_option.c		\
		ft_check_target_pos.c		\
		ft_create_stack.c			\
		ft_delete_lst_content.c		\
		ft_highest_low.c			\
		ft_lowest_high.c			\
		ft_operation_aid_back.c		\
		ft_operation_aid.c			\
		ft_operation_back.c			\
		ft_operation.c				\
		ft_sort_three.c				\
		ft_sorted_but_not_quite.c	\
		ft_stack_len.c				\
		general_algorithms.c		\
		ft_if_only_swap_two.c		\
		main.c						\
		operations_1.c				\
		operations_2.c				\
		push_swap.c					\
		stack_checkers.c			\
		stat_update.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
