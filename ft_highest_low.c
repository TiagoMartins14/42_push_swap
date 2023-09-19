/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_highest_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:40:04 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:40:13 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
