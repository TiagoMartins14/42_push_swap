/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:34:55 by tiago             #+#    #+#             */
/*   Updated: 2023/09/30 22:12:57 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*next;

	if (stack)
		stack->prev->next = NULL;
	while (stack)
	{
		next = stack->next;
		ft_delete_lst_content(&stack);
		free(stack);
		stack = next;
	}
}
