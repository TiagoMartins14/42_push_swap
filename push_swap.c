/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:28:40 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:32:02 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_stack	*head_a;
	int		cheapest_option;
	int		highest_low;
	
	stack_b = NULL;
	head_a = stack_a;
	if (ft_sorted_but_not_quite(stack_a) == 0)
	{
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
	if (if_only_swap_two(stack_a) == 0)
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
	while (ft_stack_len(stack_a) > 3)
	{
		ft_update_pos(stack_a);
		ft_update_pos(stack_b);
		ft_update_cost(stack_a, stack_b);
		cheapest_option = ft_cheapest_option(stack_a);
		if (ft_big_or_small(cheapest_option, stack_b) == 1)
			highest_low = ft_check_max(stack_b);
		else
			highest_low = ft_highest_low(stack_b, cheapest_option);
		ft_operation(&stack_a, &stack_b, cheapest_option, highest_low);
	}
	ft_sort_three(&stack_a);
	while (stack_b)
	{
		ft_update_pos(stack_a);
		ft_update_pos(stack_b);
		ft_update_cost(stack_b, stack_a);
		cheapest_option = ft_cheapest_option(stack_b);
		if (ft_big_or_small(cheapest_option, stack_a) == 1)
			highest_low = ft_check_min(stack_a); // Although I use this name, in this instance I actually use it for the opposite of what the name sugests. I am looking for the lowest highest number.
		else
			highest_low = ft_lowest_high(stack_a, cheapest_option);
		ft_operation_back(&stack_b, &stack_a, cheapest_option, highest_low);
	}
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

int	main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *next;

	int		i;
	int		j;

	if (argc == 1)
		return (write(1, "Error\n", 6));
	i = 1;
	while (argv[i]) // Check if not int
		if (ft_atol(argv[i++]) == 3333333333)
			return (write(1, "Error\n", 6));
	i = 1;
	while (argv[i]) // Check if there is a repeated int
	{
		j = i + 1;
		while (argv[j])
			if (ft_atol(argv[i]) == ft_atol(argv[j++]))
				return (write(1, "Error\n", 6));
		i++;
	}
	i = 2;
	while (argv[i])
	{
		if (ft_atol(argv[i - 1]) > ft_atol(argv[i]))
		{
			stack_a = ft_create_stack(argv);
			ft_push_swap(stack_a);
			stack_a->prev->next = NULL;
			while (stack_a)
			{
				next = stack_a->next;
				ft_delete_lst_content(&stack_a);
				free(stack_a);
				stack_a = next;
			}
			break ;
		}
		i++;
	}
	return (0);
}
void	ft_delete_lst_content(t_stack **stack)
{
	(*stack)->num = 0;
	(*stack)->cost = 0;
	(*stack)->pos = 0;
	(*stack)->rev_pos = 0;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
}
