/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:32 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 07:59:43 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_pos(t_stack *stack) 
{
	int	pos;
	int rev_pos;
	t_stack *head;
	
	pos = 1;
	rev_pos = ft_stack_len(stack);
	head = stack;
	while (stack)
	{
		stack->pos = pos;
		stack->rev_pos = rev_pos;
		pos++;
		rev_pos--;
		stack = stack->next;
		if (stack == head)
			break ;
	}
}

void	ft_update_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *head_a;

	head_a = stack_a;
	while (stack_a)
	{
		stack_a->cost = ft_cost(head_a, stack_b, stack_a->pos);
		stack_a = stack_a->next;
		if (stack_a == head_a)
			break ;
	}
}
