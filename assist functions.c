/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:06:11 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 10:33:09 by tiaferna         ###   ########.fr       */
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
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		num = -num;
	return (num);
}
t_stack	*ft_create_stack(char **argv)
{
	int	i;
	t_stack *head_stack;
	t_stack *current_node;

	i = 2;
	head_stack = (t_stack*)malloc(sizeof(t_stack));
	if (head_stack == NULL)
		return (NULL);
	head_stack->num = (int)ft_atol(argv[1]);
	head_stack->next = NULL;
	head_stack->prev = NULL;
	current_node = head_stack;
	while(argv[i])
	{
		current_node->next = (t_stack*)malloc(sizeof(t_stack));
		current_node->next->prev = current_node;
        current_node = current_node->next;
        current_node->num = (int)ft_atol(argv[i]);
        current_node->next = NULL;
		i++;
	}
	return (head_stack);
}
