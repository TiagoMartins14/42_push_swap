/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:32 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 12:53:02 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_pos(t_stack *stack) 
{
	int	pos;
	int rev_pos;
	
	pos = 1;
	rev_pos = ft_stack_len(stack);
	while (stack)
	{
		stack->position = pos;
		stack->rev_position = rev_pos;
		pos++;
		rev_pos--;
		stack = stack->next;
	}
}

void	ft_update_cost(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a)
	{
		stack_a->cost = ft_cost(stack_a, stack_b, stack_a->position);
		stack_a = stack_a->next;
	}
}
