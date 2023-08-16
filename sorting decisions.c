/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting decisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 18:57:45 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cheapest_option(t_stack *stack_a, t_stack *stack_b)
{
	int position;
	int	cost;
	
	cost = stack_a->cost;
	position = stack_a->pos;
	while (stack_a)
	{
		if (cost > stack_a->cost)
		{
			cost = stack_a->cost;
			position = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
	return (position);
}

void	ft_operation_aid(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->pos != 1)
	{
		if ((*stack_a)->pos < (*stack_a)->rev_pos)
			ft_ra((stack_a));
		else
			ft_rra((stack_a));
	}
	while ((*stack_b)->pos != 1)
	{
		if ((*stack_b)->pos < (*stack_b)->rev_pos)
			ft_rb((stack_b));
		else
			ft_rrb((stack_b));
	}
	return ;
}

void	ft_operation(t_stack **stack_a, t_stack **stack_b)
{
		while ((*stack_a)->pos != 1 || (*stack_b)->pos != 1)
	{ 
		if ((*stack_a)->rev_pos + 1 - (*stack_b)->rev_pos + 1 > (*stack_a)->pos - 1)
		{
			ft_ra(stack_a);
			ft_rrb(stack_b);
		}
		else if ((*stack_a)->pos - 1 > (*stack_a)->rev_pos + 1 && (*stack_b)->pos - 1 > (*stack_b)->rev_pos + 1)
			ft_rrr(stack_a, stack_b);
		else if ((*stack_a)->pos - 1 < (*stack_a)->rev_pos + 1 && (*stack_b)->pos - 1 < (*stack_b)->rev_pos + 1)
			ft_rr(stack_a, stack_b);
		else if ((*stack_b)->rev_pos + 1 - (*stack_a)->rev_pos + 1 > (*stack_b)->pos - 1)
		{
			ft_rb(stack_b);
			ft_rra(stack_a);
		}
	}
	return ;
}
