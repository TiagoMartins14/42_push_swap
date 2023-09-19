/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_but_not_quite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:42:18 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:42:27 by tiaferna         ###   ########.fr       */
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
			return (0); //almost sorted
		if (stack_a->num > stack_a->next->num)
			return (1); //not sorted
		stack_a = stack_a->next;
	}
	return (0);
}
