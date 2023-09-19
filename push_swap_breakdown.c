/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_breakdown.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:15:03 by tiago             #+#    #+#             */
/*   Updated: 2023/09/19 09:22:27 by tiaferna         ###   ########.fr       */
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
			return (0); //almost sorted
		if (stack_a->num > stack_a->next->num)
			return (1); //not sorted
		stack_a = stack_a->next;
	}
	return (0);
}
int	if_only_swap_two(t_stack *stack)
{
	t_stack *first_node;
	t_stack *second_node;
	int	min;
	int	checker;
	int	num;

	min = ft_check_min(stack);
	checker = 0;
	first_node = stack;
	while (first_node->num != min)
		first_node = first_node->next;
	num = first_node->num;
	second_node = first_node;
	while(first_node)
	{
		if (first_node->num > first_node->next->num)
		{
			checker++;
			num = first_node->num;
		}
		if (first_node->next->next == second_node)
			return (0);
		first_node = first_node->next;
		if (checker == 2 || num > first_node->next->num)
			return (1); //needs full algorithm
	}
	return (0);
}
