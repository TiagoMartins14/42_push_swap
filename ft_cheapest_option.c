/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:43:23 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 09:43:12 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cheapest_option(t_stack *stack_a)
{
	t_stack	*head_a;
	int		num;
	int		cost;

	head_a = stack_a;
	cost = stack_a->cost;
	num = stack_a->num;
	while (stack_a)
	{
		if (cost > stack_a->cost)
		{
			cost = stack_a->cost;
			num = stack_a->num;
		}
		stack_a = stack_a->next;
		if (stack_a == head_a)
			break ;
	}
	return (num);
}
