/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_lst_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:37:12 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/19 10:02:08 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_lst_content(t_stack **stack)
{
	(*stack)->num = 0;
	(*stack)->cost = 0;
	(*stack)->pos = 0;
	(*stack)->rev_pos = 0;
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
}
