/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:33:34 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/20 09:49:28 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
