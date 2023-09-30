/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:01:44 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/30 23:05:01 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	int			i;
	t_commands	*commands;
	t_commands	*temp;

	if (argc > 1)
	{
		if (argc == 1)
			return (0);
		i = 1;
		while (argv[i])
			if (ft_atol(argv[i++]) == 3333333333)
				return (write(2, "Error\n", 6));
		if (ft_check_if_repeated_int(argv) == 1)
			return (write(2, "Error\n", 6));
		commands = ft_push_swap_commands(0);
		ft_checker(argv, commands);
		while (commands)
		{
			temp = commands;
			commands = commands->next;
			free(temp->command);
			free(temp);
		}
	}
	return (0);
}
