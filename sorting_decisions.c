/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_decisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:46:10 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 07:59:33 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cheapest_option(t_stack *stack_a)
{
	t_stack *head_a;
	int num;
	int	cost;
	
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

void	ft_operation_aid(t_stack **stack_a, t_stack **stack_b, int cheapest_option, int highest_low)
{
	t_stack *head_a;
	t_stack *head_b;
	
	while ((*stack_a)->pos != 1 || (*stack_a)->num != cheapest_option)
	{
		head_a = *stack_a;
		while (head_a->num != cheapest_option)
			head_a = head_a->next;
		if (head_a->pos <= head_a->rev_pos)
			ft_ra((stack_a));
		else
			ft_rra((stack_a));
		ft_update_pos(*stack_a);
	}
	while ((*stack_b)->pos != 1 || (*stack_b)->num != highest_low)
	{
		head_b = *stack_b;
		while (head_b->num != highest_low)
			head_b = head_b->next;
		if (head_b->pos <= head_b->rev_pos)
			ft_rb((stack_b));
		else
			ft_rrb((stack_b));
		ft_update_pos(*stack_b);
	}
	ft_pb(stack_a, stack_b);
}

void	ft_operation(t_stack **stack_a, t_stack **stack_b, int cheapest_option, int highest_low)
{
	t_stack *head_a;
	t_stack *head_b;

		while ((*stack_a)->num != cheapest_option && (*stack_b)->num != highest_low)
	{
		head_a = (*stack_a);
		while (head_a->num != cheapest_option)
			head_a = head_a->next;
		head_b = (*stack_b);
		while (head_b->num != highest_low)
			head_b = head_b->next;
		if (head_a->pos - 1 < head_a->rev_pos + 1 && head_b->pos - 1 < head_b->rev_pos + 1)
			ft_rr(stack_a, stack_b);
		else if (head_b->rev_pos + 1 - head_a->rev_pos + 1 > head_b->pos - 1)
		{
			ft_rb(stack_b);
			ft_rra(stack_a);
		}
		else if (head_a->rev_pos + 1 - head_b->rev_pos + 1 > head_a->pos - 1)
		{
			ft_ra(stack_a);
			ft_rrb(stack_b);
		}
		else
			ft_rrr(stack_a, stack_b);
		ft_update_pos(*stack_a);
		ft_update_pos(*stack_b);
	}
	ft_operation_aid(stack_a, stack_b, cheapest_option, highest_low);
	//TEST
	/* t_stack *test_a;
	t_stack *test_b;
	test_a = (*stack_a);
	test_b = (*stack_b);
	while (test_a)
	{
		printf("%d ", (*test_a).num);
		test_a = (*test_a).next;
		if (test_a == (*stack_a))
			break;
	}
	printf("\n.\n.\n");
	while (test_b)
	{
		printf("%d ", (*test_b).num);
		test_b = (*test_b).next;
		if (test_b == (*stack_b))
			break;
	}
	printf("\n.\n.\n"); */
	//TEST
}
// REVERSE

void	ft_operation_aid_back(t_stack **stack_b, t_stack **stack_a, int cheapest_option, int highest_low)
{
	t_stack *head_b;
	t_stack *head_a;
	
	while ((*stack_b)->pos != 1 || (*stack_b)->num != cheapest_option)
	{
		head_b = *stack_b;
		while (head_b->num != cheapest_option)
			head_b = head_b->next;
		if (head_b->pos <= head_b->rev_pos)
			ft_rb((stack_b));
		else
			ft_rrb((stack_b));
		ft_update_pos(*stack_b);
	}
	while ((*stack_a)->pos != 1 || (*stack_a)->num != highest_low)
	{
		head_a = *stack_a;
		while (head_a->num != highest_low)
			head_a = head_a->next;
		if (head_a->pos <= head_a->rev_pos)
			ft_ra((stack_a));
		else
			ft_rra((stack_a));
		ft_update_pos(*stack_a);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_operation_back(t_stack **stack_b, t_stack **stack_a, int cheapest_option, int highest_low)
{
	t_stack *head_b;
	t_stack *head_a;

		while ((*stack_b)->num != cheapest_option && (*stack_a)->num != highest_low)
	{
		head_b = (*stack_b);
		while (head_b->num != cheapest_option)
			head_b = head_b->next;
		head_a = (*stack_a);
		while (head_a->num != highest_low)
			head_a = head_a->next;
		if (head_b->pos - 1 < head_b->rev_pos + 1 && head_a->pos - 1 < head_a->rev_pos + 1)
			ft_rr(stack_b, stack_a);
		else if (head_a->rev_pos + 1 - head_b->rev_pos + 1 > head_a->pos - 1)
		{
			ft_ra(stack_a);
			ft_rrb(stack_b);
		}
		else if (head_b->rev_pos + 1 - head_a->rev_pos + 1 > head_b->pos - 1)
		{
			ft_rb(stack_b);
			ft_rra(stack_a);
		}
		else
			ft_rrr(stack_b, stack_a);
		ft_update_pos(*stack_b);
		ft_update_pos(*stack_a);
	}
	ft_operation_aid_back(stack_b, stack_a, cheapest_option, highest_low);
}
