/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_aid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:43:53 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 09:55:28 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operation_aid(t_stack **stack_a, t_stack **stack_b, \
							int cheapest_option, int highest_low)
{
	t_stack	*head_a;
	t_stack	*head_b;

	while ((*stack_a)->pos != 1 || (*stack_a)->num != cheapest_option)
	{
		head_a = *stack_a;
		while (head_a->num != cheapest_option)
			head_a = head_a->next;
		if (head_a->pos <= head_a->rev_pos)
			ft_ra((stack_a));
		else
			ft_rra((stack_a));
		ft_update_pos(*stack_a);
	}
	while ((*stack_b)->pos != 1 || (*stack_b)->num != highest_low)
	{
		head_b = *stack_b;
		while (head_b->num != highest_low)
			head_b = head_b->next;
		if (head_b->pos <= head_b->rev_pos)
			ft_rb((stack_b));
		else
			ft_rrb((stack_b));
		ft_update_pos(*stack_b);
	}
}
