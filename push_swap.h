/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:39:45 by tiaferna          #+#    #+#             */
/*   Updated: 2023/08/14 18:41:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_stack
{
	int	num;
	int cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

long	ft_atol(char *str);

t_stack	*ft_create_stack(char **argv);

void	ft_push_swap(char *str);
void	ft_swap_top_two(t_stack **head);
void	ft_push_to_stack(t_stack **head_x, t_stack **head_y);
void	ft_bottom_to_top(t_stack **head);
void	ft_top_to_bottom(t_stack **head);
void	ft_sort_three(t_stack **stack);

int	ft_check_min(t_stack *stack);
int	ft_check_max(t_stack *stack);
int	ft_cost_of_highest(t_stack *stack);

#endif