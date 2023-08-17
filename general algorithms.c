/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:56 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/17 11:59:20 by tiaferna         ###   ########.fr       */
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

void	ft_push_to_stack(t_stack **stack_x, t_stack **stack_y)
{
    t_stack *new_node;
    
    if (*stack_x == NULL)
        return;
    
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return;
    
    new_node->num = (*stack_x)->num;
    
    if (!(*stack_y)) {
        new_node->next = new_node; // Circular link to itself
        new_node->prev = new_node;
        *stack_y = new_node; // Update the head of stack_y
    } else {
        new_node->next = *stack_y; // New node points to the old head
        new_node->prev = (*stack_y)->prev; // New node's prev points to the old last node
        (*stack_y)->prev->next = new_node; // Update the old last node's next
        *stack_y = new_node; // Update the old head's prev
    }
    (*stack_x)->prev->next = (*stack_x)->next;
	(*stack_x)->next->prev = (*stack_x)->prev;
    *stack_x = (*stack_x)->next; // Move to the next node in stack_x
}

void	ft_bottom_to_top(t_stack **head)
{
    if (*head == NULL || (*head)->next == *head) {
        return;
    }

    t_stack *first_node = *head;
    t_stack *last_node = (*head)->prev;
    t_stack *new_last_node = last_node->prev;

    *head = last_node;
    first_node->prev = last_node;
    last_node->next = first_node;

    last_node->prev = new_last_node;
    new_last_node->next = last_node;
}
void ft_top_to_bottom(t_stack **head)
{
    if (*head == NULL || (*head)->next == *head) {
        return;
    }

    t_stack *first_node = *head;
    t_stack *last_node = (*head)->prev;

    *head = first_node->next;
    last_node->next = first_node;
    first_node->prev = last_node;

    first_node->next = last_node;
    last_node->prev = first_node;
}
