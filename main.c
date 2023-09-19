/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:37:54 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:38:22 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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