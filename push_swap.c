/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:28:40 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 23:44:07 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_stack	*head_a;
	
	stack_b = NULL;
	head_a = stack_a;
	if (ft_sorted_but_not_quite(stack_a) == 0)
	{
		ft_sorted_but_not_quite_aid(stack_a);
		return ;
	}
	if (ft_if_only_swap_two(stack_a) == 0)
	{
		int	count;
		int	direction;
		int	distance;
		
		count = 0;
		distance = 0;
		while (stack_a->num < stack_a->next->num)
		{
			stack_a = stack_a->next;
			distance++;
		}
		if (distance <= ft_stack_len(stack_a) / 2)
		{
			while (head_a->num != stack_a->num)
			{
				ft_rra(&stack_a);
				count++;
			}
			direction = 0;
		}
		else
		{
			while (head_a->num != stack_a->num)
			{
				ft_ra(&stack_a);
				count++;
			}
			direction = 1;
		}
		ft_swap_top_two(&stack_a);
		write(1, "sa\n", 3);
		while (count-- > 0)
		{
			if (direction == 1)
				ft_ra(&stack_a);
			else
				ft_rra(&stack_a);
		}
		return ;
	}
	if (ft_stack_len(stack_a) == 3)
	{
		ft_sort_three(&stack_a);
		return ;
	}
	ft_pb(&stack_a, &stack_b);
	ft_a_to_b(&stack_a, &stack_b);
	ft_sort_three(&stack_a);
	ft_b_to_a(&stack_b, &stack_a);
	head_a = stack_a;
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

void	ft_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	cheapest_option;
	int	highest_low;
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

void	ft_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	int	cheapest_option;
	int	highest_low;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	while (head_b)
	{
		ft_update_pos(head_a);
		ft_update_pos(head_b);
		ft_update_cost(head_b, head_a);
		cheapest_option = ft_cheapest_option(head_b);
		if (ft_big_or_small(cheapest_option, head_a) == 1)
			highest_low = ft_check_min(head_a); // Although I use this name, in this instance I actually use it for the opposite of what the name sugests. I am looking for the lowest highest number.
		else
			highest_low = ft_lowest_high(head_a, cheapest_option);
		ft_operation_back(stack_b, stack_a, cheapest_option, highest_low);
		head_a = *stack_a;
		head_b = *stack_b;
	}
	return ;
}
