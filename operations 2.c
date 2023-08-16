/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations 2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:19:26 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 11:31:12 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack)
{
	ft_bottom_to_top(stack);
	write(1, "rra\n", 4);
	return ;
}

void	ft_rrb(t_stack **stack)
{
	ft_bottom_to_top(stack);
	write(1, "rrb\n", 4);
	return ;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_bottom_to_top(stack_a);
	ft_bottom_to_top(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
