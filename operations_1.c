// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:11:54 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 07:59:06 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_to_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
	return ;
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_to_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
	return ;
}

void	ft_ra(t_stack **stack)
{
	ft_top_to_bottom(stack);
	write(1, "ra\n", 3);
	return ;
}

void	ft_rb(t_stack **stack)
{
	ft_top_to_bottom(stack);
	write(1, "rb\n", 3);
	return ;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_top_to_bottom(stack_a);
	ft_top_to_bottom(stack_b);
	write(1, "rr\n", 3);
	return ;
}
