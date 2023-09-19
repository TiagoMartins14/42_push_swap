/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_target_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:18:46 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 08:23:32 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "push_swap.h"

int	ft_check_target_pos(t_stack *stack)
{
	int		min;
	int		target_pos;
	t_stack	*head;

	min = stack->num;
	head = stack;
	while (stack)
	{
		if (min > stack->num)
		{
			min = stack->num;
			target_pos = stack->pos;
		}
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (target_pos);
}