/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_breakdown.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:15:03 by tiago             #+#    #+#             */
/*   Updated: 2023/09/18 23:12:56 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_but_not_quite(t_stack *stack_a)
{
	t_stack 	*head_a;
	int			min;

	min = ft_check_min(stack_a);
	while (stack_a->num != min)
		stack_a = stack_a->next;
	head_a = stack_a;
	while (stack_a)
	{
		if (stack_a->next == head_a)
			return (0);
		if (stack_a->num > stack_a->next->num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
int	if_only_swap_top(t_stack *stack)
{
	t_stack *first_node;
	t_stack *second_node;

	first_node = stack;
	second_node = stack->next;
	stack = stack->next->next;
	if (first_node->num < second_node->num)
		return (0);
	while (stack)
	{
		if (first_node->num > stack->num || second_node->num > stack->num)
			return (0);
		stack = stack->next;
		if (stack == first_node)
			break;
	}
	return (1);
}
