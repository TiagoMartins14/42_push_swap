/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:28:40 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/02 10:54:03 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_sorted_but_not_quite(stack_a) == 0)
		ft_sorted_but_not_quite_aid(stack_a);
	else if (ft_stack_len(stack_a) == 3)
		ft_sort_three(&stack_a);
	else
	{
		ft_pb(&stack_a, &stack_b);
		ft_a_to_b(&stack_a, &stack_b);
		ft_sort_three(&stack_a);
		ft_b_to_a(&stack_b, &stack_a);
		ft_sorted_but_not_quite_aid(stack_a);
	}
	return ;
}
