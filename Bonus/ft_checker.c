/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:01:44 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 11:46:16 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

t_stack	*ft_push_swap_commands(int fd)
{
	t_commands	*commands;

	commands = get_next_line(fd);
	while (commands->command != NULL)
	{
		commands = commands->next;
		commands->command = get_next_line(fd);
		commands->next = NULL;
	}
	return (commands);
}

void	ft_checker(t_stack *stack_a, s_commands *commands)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (commands)
	{
		if (commands->command == "pa\n")
			ft_push_to_stack(stack_b, stack_a);
		else if (commands->command == "pb\n")
			ft_push_to_stack(stack_a, stack_b);
		else if (commands->command == "ra\n")
			ft_top_to_bottom(stack);
		else if (commands->command == "rb\n")
			ft_top_to_bottom(stack);
		else if (commands->command == "rr\n")
		{
			ft_top_to_bottom(stack_a);
			ft_top_to_bottom(stack_b);
		}
	}
}
