/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_or_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:39:40 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 09:39:55 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if num is higher or lower than any other number in the given stack
int	ft_big_or_small(int num, t_stack *stack)
{
	int	max;
	int	min;

	max = ft_check_max(stack);
	min = ft_check_min(stack);
	if (num < min || num > max)
		return (1); // It IS
	return (0); // It is NOT
}
