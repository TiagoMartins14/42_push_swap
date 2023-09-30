/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:36:04 by tiago             #+#    #+#             */
/*   Updated: 2023/09/30 18:40:00 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_checker(char	**argv, t_commands *commands)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_stack(argv);
	stack_b = NULL;
	while (commands)
	{
		if (ft_command_action(commands, &stack_a, &stack_b) == 1)
		{
			write(2, "Error\n", 6);
			ft_free_stack(stack_a);
			ft_free_stack(stack_b);
			return ;
		}
		commands = commands->next;
	}
	if (ft_is_stack_sorted(stack_a) == 0 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
