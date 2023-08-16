/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:32 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 18:38:52 by tiago            ###   ########.fr       */
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
		stack->pos = pos;
		stack->rev_pos = rev_pos;
		pos++;
		rev_pos--;
		stack = stack->next;
	}
}

void	ft_update_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *head_a;

	head_a = stack_a;
	while (stack_a)
	{
		stack_a->cost = ft_cost(stack_a, stack_b, stack_a->pos);
		stack_a = stack_a->next;
		if (stack_a == head_a)
			break ;
	}
}
