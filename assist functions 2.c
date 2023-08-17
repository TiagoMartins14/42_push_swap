/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist functions 2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:30:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/17 10:24:52 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the lenght of the stack
int	ft_stack_len(t_stack *stack)
{
	int	len;
	t_stack *head;

	len = 0;
	head = stack;
	while (stack)
	{
		len++;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (len);
}

// Checks if num is higher or lower than any other number in the given stack
int	ft_big_or_small(int num, t_stack *stack)
{
	int	max;
	int	min;

	max = ft_check_max(stack);
	min = ft_check_min(stack);
	if (num < min || num > max)
		return (1); // It IS
	return (0); // It is NOT
}

// Checks the highest low number in the stack compared to the given num
int	ft_highest_low(t_stack *stack, int num)
{
	int highest_low;
	t_stack *head;

	highest_low = ft_check_min(stack);
	head = stack;
	if (highest_low > num)
		return (ft_check_max(stack));
	while (stack)
	{
		if (stack->num < num && stack->num > highest_low)
			highest_low = stack->num;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (highest_low);
}