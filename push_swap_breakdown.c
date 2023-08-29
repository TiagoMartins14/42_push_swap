/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_breakdown.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:15:03 by tiago             #+#    #+#             */
/*   Updated: 2023/08/29 15:52:15 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_but_not_quite(t_stack *stack_a)
{
	t_stack 	*head_a;
	int			min;

	min = ft_check_min(stack_a);
	while (stack_a->num != min)
		stack_a = stack_a->next;
	head_a = stack_a;
	while (stack_a)
	{
		if (stack_a->next == head_a)
			return (0);
		if (stack_a->num > stack_a->next->num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
