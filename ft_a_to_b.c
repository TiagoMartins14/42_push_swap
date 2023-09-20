/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:11:21 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 09:35:09 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest_option;
	int		highest_low;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	while (ft_stack_len(head_a) > 3)
	{
		ft_update_pos(head_a);
		ft_update_pos(head_b);
		ft_update_cost(head_a, head_b);
		cheapest_option = ft_cheapest_option(head_a);
		if (ft_big_or_small(cheapest_option, head_b) == 1)
			highest_low = ft_check_max(head_b);
		else
			highest_low = ft_highest_low(head_b, cheapest_option);
		ft_operation(stack_a, stack_b, cheapest_option, highest_low);
		head_a = *stack_a;
		head_b = *stack_b;
	}
	return ;
}
