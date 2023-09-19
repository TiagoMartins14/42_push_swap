/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:30:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:40:19 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lowest_high(t_stack *stack, int num)
{
	int lowest_high;
	t_stack *head;

	lowest_high = ft_check_max(stack);
	head = stack;
	if (lowest_high < num)
		return (ft_check_min(stack));
	while (stack)
	{
		if (stack->num > num && stack->num < lowest_high)
			lowest_high = stack->num;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (lowest_high);
}
