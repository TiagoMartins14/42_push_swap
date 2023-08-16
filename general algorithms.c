/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:56 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/16 19:08:47 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_top_two(t_stack **head)
{
	int	temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = temp;
}

void	ft_push_to_stack(t_stack **head_x, t_stack **head_y)
{
	t_stack	*new_node;
	
	if (*head_x == NULL)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = (*head_x)->num;
	new_node->next = *head_y;
	*head_y = new_node;
	*head_x = (*head_x)->next;
}
void	ft_bottom_to_top(t_stack **head)
{
	t_stack	*last_node;
	t_stack *second_last_node;
	
	if (*head == NULL || (*head)->next == NULL)
		return ;
	last_node = *head;
	second_last_node = NULL;
	while (last_node->next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *head;
	*head = last_node;
	if (second_last_node != NULL)
        second_last_node->next = NULL;
}
void ft_top_to_bottom(t_stack **head)
{
	t_stack *last_node;
	
	last_node = *head;
    if (*head == NULL || (*head)->next == NULL)
        return;
    while (last_node->next)
        last_node = last_node->next;
    last_node->next = *head;
    *head = (*head)->next;
    last_node->next->next = NULL;
}
