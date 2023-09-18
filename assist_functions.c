/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:06:11 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/18 11:40:25 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (3333333333);
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		num = -num;
	if (num > 2147483647 || num < -2147483648)
		return (3333333333); // error value
	return (num);
}
t_stack	*ft_create_stack(char **argv)
{
	int	i;
	t_stack *head_stack;
	t_stack *current_node;

	i = 1;
	head_stack = (t_stack*)malloc(sizeof(t_stack));
	if (head_stack == NULL)
		return (NULL);
	head_stack->num = (int)ft_atol(argv[1]);
	head_stack->next = NULL;
	head_stack->prev = NULL;
	head_stack->pos = 0;
	head_stack->rev_pos = 0;
	head_stack->cost = 0;
	current_node = head_stack;
	while(argv[++i])
	{
		current_node->next = (t_stack*)malloc(sizeof(t_stack));
		current_node->next->prev = current_node;
        current_node = current_node->next;
        current_node->num = (int)ft_atol(argv[i]);
        current_node->next = head_stack;
	}
	head_stack->prev = current_node;
	return (head_stack);
}
