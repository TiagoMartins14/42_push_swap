/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_decisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:45:23 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operation_back(t_stack **stack_b, t_stack **stack_a, int cheapest_option, int highest_low)
{
	t_stack *head_b;
	t_stack *head_a;

		while ((*stack_b)->num != cheapest_option && (*stack_a)->num != highest_low)
	{
		head_b = (*stack_b);
		while (head_b->num != cheapest_option)
			head_b = head_b->next;
		head_a = (*stack_a);
		while (head_a->num != highest_low)
			head_a = head_a->next;
		if (head_b->pos - 1 < head_b->rev_pos + 1 && head_a->pos - 1 < head_a->rev_pos + 1)
			ft_rr(stack_b, stack_a);
		else if (head_a->rev_pos + 1 - head_b->rev_pos + 1 > head_a->pos - 1)
		{
			ft_ra(stack_a);
			ft_rrb(stack_b);
		}
		else if (head_b->rev_pos + 1 - head_a->rev_pos + 1 > head_b->pos - 1)
		{
			ft_rb(stack_b);
			ft_rra(stack_a);
		}
		else
			ft_rrr(stack_b, stack_a);
		ft_update_pos(*stack_b);
		ft_update_pos(*stack_a);
	}
	ft_operation_aid_back(stack_b, stack_a, cheapest_option, highest_low);
}
