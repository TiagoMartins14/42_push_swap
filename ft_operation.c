/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:44:47 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:44:55 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operation(t_stack **stack_a, t_stack **stack_b, int cheapest_option, int highest_low)
{
	t_stack *head_a;
	t_stack *head_b;

		while ((*stack_a)->num != cheapest_option && (*stack_b)->num != highest_low)
	{
		head_a = (*stack_a);
		while (head_a->num != cheapest_option)
			head_a = head_a->next;
		head_b = (*stack_b);
		while (head_b->num != highest_low)
			head_b = head_b->next;
		if (head_a->pos - 1 < head_a->rev_pos + 1 && head_b->pos - 1 < head_b->rev_pos + 1)
			ft_rr(stack_a, stack_b);
		else if (head_b->rev_pos + 1 - head_a->rev_pos + 1 > head_b->pos - 1)
		{
			ft_rb(stack_b);
			ft_rra(stack_a);
		}
		else if (head_a->rev_pos + 1 - head_b->rev_pos + 1 > head_a->pos - 1)
		{
			ft_ra(stack_a);
			ft_rrb(stack_b);
		}
		else
			ft_rrr(stack_a, stack_b);
		ft_update_pos(*stack_a);
		ft_update_pos(*stack_b);
	}
	ft_operation_aid(stack_a, stack_b, cheapest_option, highest_low);
}
