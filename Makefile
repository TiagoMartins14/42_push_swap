# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiago <tiago@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 23:48:53 by tiago             #+#    #+#              #
#    Updated: 2023/08/29 15:41:49 by tiago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs

SRCS = assist_functions_2.c		\
		assist_functions.c		\
		general_algorithms.c	\
		operations_1.c			\
		operations_2.c			\
		push_swap_breakdown.c	\
		push_swap.c				\
		sort_functions.c		\
		sorting_decisions.c		\
		stack_checkers.c		\
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