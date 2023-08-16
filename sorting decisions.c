/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting decisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 12:56:21 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cheapest_option(t_stack *stack_a, t_stack *stack_b)
{
	int position;
	int	cost;
	
	cost = stack_a->cost;
	position = stack_a->position;
	while (stack_a)
	{
		if (cost > stack_a->cost)
		{
			cost = stack_a->cost;
			position = stack_a->position;
		}
		stack_a = stack_a->next;
	}
	return (position);
}

void	ft_operation(t_stack **stack_a, t_stack **stack_b)
{
	int	lower_cost;
	int	move; // 1 - A and B up; 2 - A up and B down; 3 - A and B down; 4 - A down and B up
	int len_a;
	int len_b;

	len_a = ft_stack_len(&stack_a);
	len_b = ft_stack_len(&stack_b);
	lower_cost = len_a;
	if (len_a > len_b)
		lower_cost = len_b;
	while ((*stack_a)->position != 1 && (*stack_b)->position != 1)
	{
		
	}
	
/* 	int	cost;
	int	move; // 1 - A up; 2 - A and B up; 3 - A up and B down; 4 - A and B down; 5 - A down and B up

	cost = (*stack_a)->position - 1; // Cost of only A going up
	move = 1
	if (cost < position_b - 1)
		cost = position_b - 1; // A and B up
	if (cost > ((position_a - 1) + (len_b - position_b + 1))) // A up and B down
		cost = ((position_a - 1) + (len_b - position_b + 1));
	if (cost > len_a - position_a + 1 && cost > len_b - position_b + 1) // A and B down
		{
			if ((len_a - position_a + 1) > (len_b - position_b + 1))
				cost = len_a - position_a + 1;
			else
				cost = len_b - position_b + 1;
		}
	if (cost > (len_a - position_a + 1) + position_b - 1) // A down and B up
		cost = (len_a - position_a + 1) + position_b - 1;
	return (cost); */
}
