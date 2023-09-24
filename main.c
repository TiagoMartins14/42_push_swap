/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:37:54 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/24 19:22:51 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return (0);
	i = 1;
	while (argv[i])
		if (ft_atol(argv[i++]) == 3333333333)
			return (write(1, "Error\n", 6));
	if (ft_check_if_repeated_int(argv) == 1)
		return (write(1, "Error\n", 6));
	ft_full_push_swap(argv);
	return (0);
}

void	ft_full_push_swap(char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*next;

	i = 2;
	stack_a = NULL;
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
	return ;
}
