/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist functions 2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:30:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 19:14:05 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the lenght of the stack
int	ft_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

// Checks if num is higher or lower than any other number in the given stack
int	ft_big_or_low(int num, t_stack *stack)
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

	highest_low = ft_check_min(stack);
	if (highest_low > num)
		return (ft_check_max(stack));
	while (stack)
	{
		if (stack->num < num && stack->num > highest_low)
			highest_low = stack->num;
		stack = stack->next;
	}
	return (highest_low);
}