# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 23:48:53 by tiago             #+#    #+#              #
#    Updated: 2023/10/02 10:51:48 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRCS = 	ft_a_to_b.c 					\
		ft_atol.c						\
		ft_argcheck.c					\
		ft_b_to_a.c						\
		ft_big_or_small.c				\
		ft_cheapest_option.c			\
		ft_check_if_repeated_int.c		\
		ft_check_target_pos.c			\
		ft_create_stack.c				\
		ft_delete_lst_content.c			\
		ft_full_push_swap.c				\
		ft_highest_low.c				\
		ft_lowest_high.c				\
		ft_operation_aid_back.c			\
		ft_operation_aid.c				\
		ft_operation_back.c				\
		ft_operation.c					\
		ft_sort_three.c					\
		ft_sorted_but_not_quite_aid.c	\
		ft_sorted_but_not_quite.c		\
		ft_stack_len.c					\
		ft_strcmp.c						\
		general_algorithms.c			\
		main.c							\
		operations_1.c					\
		operations_2.c					\
		ft_push_swap.c					\
		stack_checkers.c				\
		stat_update.c

BONUS_SRCS =	bonus/ft_checker_bonus.c			\
				bonus/ft_command_action_bonus.c		\
				bonus/ft_free_stack_bonus.c			\
				bonus/ft_push_swap_commands_bonus.c	\
				bonus/ft_strdup_bonus.c				\
				bonus/main_bonus.c					\
				get_next_line/get_next_line.c		\
				get_next_line/get_next_line_utils.c	\
				ft_a_to_b.c 						\
				ft_atol.c							\
				ft_argcheck.c						\
				ft_b_to_a.c							\
				ft_big_or_small.c					\
				ft_cheapest_option.c				\
				ft_check_if_repeated_int.c			\
				ft_check_target_pos.c				\
				ft_create_stack.c					\
				ft_delete_lst_content.c				\
				ft_full_push_swap.c					\
				ft_highest_low.c					\
				ft_lowest_high.c					\
				ft_operation_aid_back.c				\
				ft_operation_aid.c					\
				ft_operation_back.c					\
				ft_operation.c						\
				ft_sort_three.c						\
				ft_sorted_but_not_quite_aid.c		\
				ft_sorted_but_not_quite.c			\
				ft_stack_len.c						\
				ft_strcmp.c							\
				general_algorithms.c				\
				operations_1.c						\
				operations_2.c						\
				ft_push_swap.c						\
				stack_checkers.c					\
				stat_update.c

		
OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) 

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -I . -o $@

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
