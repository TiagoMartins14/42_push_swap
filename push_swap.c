/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:28:40 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 11:08:27 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *stack_a)
{
	t_stack *stack_b;
	t_stack *head_a;
	t_stack *head_b;
	
	head_a = stack_a;
	
	ft_push_to_stack(&stack_a, &stack_b);
	ft_push_to_stack(&stack_a, &stack_b);
	
	head_b = stack_b;
	
	while (ft_is_stack_sorted(stack_a) == 1)
	{
		
		
		if (ft_is_stack_sorted(stack_a) == 0 && ft_stack_len(stack_b) == 0)
			return ;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	
	stack_a = ft_create_stack(argv);
	
	ft_push_swap(stack_a);



	
	/* stack_b = (t_stack *)malloc(sizeof(t_stack));
	ft_push_to_stack(&stack_a, &stack_b);
	ft_push_to_stack(&stack_a, &stack_b);
	ft_push_to_stack(&stack_a, &stack_b);
	ft_push_to_stack(&stack_a, &stack_b);

	ft_update_pos(stack_a);
	ft_update_pos(stack_b);
	head_a = stack_a;
	head_b = stack_b;

	printf("STACK A\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	printf("\nSTACK B\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->num);
		stack_b = stack_b->next;
	}

	stack_a = head_a;
	stack_b = head_b;
	
	while (stack_a)
	{
		printf("Number %d position: %d\n", stack_a->num, stack_a->position);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("Number %d position: %d\n", stack_b->num, stack_b->position);
		stack_b = stack_b->next;
	}
	
	int value;

	value = ft_cost(head_a, head_b, 5);
	printf("head_b length - b position + 1: %d - %d + 1", ft_stack_len(head_b), head_b->next->next->position);
	printf("\nCOST OF NUMBER IN POSITION 5 IN STACK A: %d\n", value);

	
	printf("The lowest number is: %d\n", ft_check_min(stack_a));
	printf("The highest number is: %d\n", ft_check_max(stack_a));	

	printf("%d\n", ft_cost_of_highest(stack_a));

	
	printf("Unsorted list\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->num);
		stack_b = stack_b->next;
	}
	ft_sort_three(&head_b);
	printf("\nSorted list\n");
	while (head_b)
	{
		printf("%d\n", head_b->num);
		head_b = head_b->next;
	} */
	return (0);
}
