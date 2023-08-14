/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:06:11 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/14 19:04:38 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		num = -num;
	return (num);
}
t_stack	*ft_create_stack(char **argv)
{
	int	i;
	t_stack *head_stack;
	t_stack *current_node;

	i = 2;
	head_stack = (t_stack*)malloc(sizeof(t_stack));
	if (head_stack == NULL)
		return (NULL);
	head_stack->num = (int)ft_atol(argv[1]);
	head_stack->next = NULL;
	head_stack->prev = NULL;
	current_node = head_stack;
	while(argv[i])
	{
		current_node->next = (t_stack*)malloc(sizeof(t_stack));
		current_node->next->prev = current_node;
        current_node = current_node->next;
        current_node->num = (int)ft_atol(argv[i]);
        current_node->next = NULL;
		i++;
	}
	return (head_stack);
}

int	ft_check_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	ft_check_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int ft_cost(t_stack *stack)
{
	// 1 - check if the number is bigger or lower than any other number in the oposite stack

	// 2 - otherwise check which is the highest lower number in the oposite stack

	// 3 - check if the number is above or bellow the middle of the stack

	// 4 - check how many moves it needs to get to the top of the stack (either by going up or down)

	// 5 - if both need to rotate in same direction, count as only one move
}


//cost of bringing the highest number to the top of the stack
int	ft_cost_of_highest(t_stack *stack)
{
	t_stack *head;
	int		count;
	int		value;
	int		num;
	
	count = 0;
	value = count;
	num = stack->num;
	while (stack)
	{
		if (num < stack->num)
		{
			value = count;
			num = stack->num;
		}
		count++;
		stack = stack->next;
	}
	if (value * 2 > count)
		value = count - value;
	return (value);
}
