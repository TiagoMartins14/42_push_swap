/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:11:24 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 09:37:17 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	int		cheapest_option;
	int		lowest_high;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	while (head_b)
	{
		ft_update_pos(head_a);
		ft_update_pos(head_b);
		ft_update_cost(head_b, head_a);
		cheapest_option = ft_cheapest_option(head_b);
		if (ft_big_or_small(cheapest_option, head_a) == 1)
			lowest_high = ft_check_min(head_a);
		else
			lowest_high = ft_lowest_high(head_a, cheapest_option);
		ft_operation_back(stack_b, stack_a, cheapest_option, lowest_high);
		head_a = *stack_a;
		head_b = *stack_b;
	}
	return ;
}
