/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:28:40 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/14 18:49:36 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char *str)
{
	
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *head_a;
	t_stack *head_b;
	
	stack_a = ft_create_stack(argv);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	head_a = stack_a;
	head_b = stack_b;

	
/* 	printf("The lowest number is: %d\n", ft_check_min(stack_a));
	printf("The highest number is: %d\n", ft_check_max(stack_a));	

	printf("%d\n", ft_cost_of_highest(stack_a)); */

	
/* 	printf("Unsorted list\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_sort_three(&head);
	printf("\nSorted list\n");
	while (head)
	{
		printf("%d\n", head->num);
		head = head->next;
	} */
	return (0);
}
