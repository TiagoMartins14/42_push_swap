/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_action_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:33:43 by tiago             #+#    #+#             */
/*   Updated: 2023/10/02 10:44:53 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../push_swap.h"

int	ft_command_action(t_commands *commands, \
						t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(commands->command, "sa\n") == 0)
		ft_swap_top_two(stack_a);
	else if (ft_strcmp(commands->command, "sb\n") == 0)
		ft_swap_top_two(stack_b);
	else if (ft_strcmp(commands->command, "pa\n") == 0)
		ft_push_to_stack(stack_b, stack_a);
	else if (ft_strcmp(commands->command, "pb\n") == 0)
		ft_push_to_stack(stack_a, stack_b);
	else if (ft_strcmp(commands->command, "ra\n") == 0)
		ft_top_to_bottom(stack_a);
	else if (ft_strcmp(commands->command, "rb\n") == 0)
		ft_top_to_bottom(stack_b);
	else if (ft_strcmp(commands->command, "rr\n") == 0)
		ft_double_top_to_bottom(stack_a, stack_b);
	else if (ft_strcmp(commands->command, "rra\n") == 0)
		ft_bottom_to_top(stack_a);
	else if (ft_strcmp(commands->command, "rrb\n") == 0)
		ft_bottom_to_top(stack_b);
	else if (ft_strcmp(commands->command, "rrr\n") == 0)
		ft_double_bottom_to_top(stack_a, stack_b);
	else
		return (1);
	return (0);
}

void	ft_double_top_to_bottom(t_stack **stack_a, t_stack **stack_b)
{
	ft_top_to_bottom(stack_a);
	ft_top_to_bottom(stack_b);
}

void	ft_double_bottom_to_top(t_stack **stack_a, t_stack **stack_b)
{
	ft_bottom_to_top(stack_a);
	ft_bottom_to_top(stack_b);
}
