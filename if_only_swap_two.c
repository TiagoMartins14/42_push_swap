/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_only_swap_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:15:03 by tiago             #+#    #+#             */
/*   Updated: 2023/09/19 09:50:07 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_only_swap_two(t_stack *stack)
{
	t_stack *first_node;
	t_stack *second_node;
	int	min;
	int	checker;
	int	num;

	min = ft_check_min(stack);
	checker = 0;
	first_node = stack;
	while (first_node->num != min)
		first_node = first_node->next;
	num = first_node->num;
	second_node = first_node;
	while(first_node)
	{
		if (first_node->num > first_node->next->num)
		{
			checker++;
			num = first_node->num;
		}
		if (first_node->next->next == second_node)
			return (0);
		first_node = first_node->next;
		if (checker == 2 || num > first_node->next->num)
			return (1); //needs full algorithm
	}
	return (0);
}
