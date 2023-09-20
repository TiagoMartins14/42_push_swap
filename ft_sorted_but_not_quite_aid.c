/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_but_not_quite_aid.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:11:17 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 09:57:50 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorted_but_not_quite_aid(t_stack *stack_a)
{
	t_stack	*head_a;

	head_a = stack_a;
	ft_update_pos(head_a);
	while (head_a->num != ft_check_min(stack_a))
		head_a = head_a->next;
	while (stack_a->num != ft_check_min(stack_a))
	{
		if (head_a->pos <= head_a->rev_pos)
			ft_ra(&stack_a);
		else
			ft_rra(&stack_a);
	}
	return ;
}
