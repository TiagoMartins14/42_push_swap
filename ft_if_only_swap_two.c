/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_only_swap_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:15:03 by tiago             #+#    #+#             */
/*   Updated: 2023/09/24 20:49:05 by tiago            ###   ########.fr       */
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
	return (ft_if_only_swap_two_aid(first_node, second_node, checker, num));
}

int	ft_if_only_swap_two_aid(t_stack *first_node, t_stack *second_node, int checker, int num)
{
	while(first_node)
	{
		if (first_node->num > first_node->next->num)
		{
			checker++;
			num = first_node->num;
		}
		if (checker == 2)
			return (1); //needs full algorithm
		if (first_node->next->next == second_node)
			return (0);
		first_node = first_node->next;
		if (num > first_node->next->num)
			return (1);
	}
	return  (0);
}
