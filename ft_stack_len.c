/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:39:11 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:39:28 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the lenght of the stack
int	ft_stack_len(t_stack *stack)
{
	int	len;
	t_stack *head;

	len = 0;
	head = stack;
	while (stack)
	{
		len++;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (len);
}
