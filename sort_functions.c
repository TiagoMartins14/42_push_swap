/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:22:00 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 07:59:28 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num && \
	(*stack)->next->num < (*stack)->next->next->num)
		return ;
	if ((*stack)->next->num > (*stack)->num && \
	(*stack)->next->num > (*stack)->next->next->num)
	{
		ft_bottom_to_top(stack);
		write(1, "rra\n", 4);
	}
	if ((*stack)->num > (*stack)->next->num && \
	(*stack)->num > (*stack)->next->next->num)
	{
		ft_top_to_bottom(stack);
		write(1, "ra\n", 3);
	}
	if ((*stack)->next->num < (*stack)->num && \
	(*stack)->next->num < (*stack)->next->next->num)
	{
		ft_swap_top_two(stack);
		write(1, "sa\n", 3);
	}
}
