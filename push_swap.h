/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:39:45 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/21 17:22:52 by tiago            ###   ########.fr       */
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
	int				num;
	int				cost;
	int				pos;
	int				rev_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_create_stack(char **argv);

long	ft_atol(char *str);

void	ft_push_swap(t_stack *stack_a);
void	ft_swap_top_two(t_stack **head);
void	ft_push_to_stack(t_stack **head_x, t_stack **head_y);
void	ft_bottom_to_top(t_stack **head);
void	ft_top_to_bottom(t_stack **head);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack);
void	ft_update_pos(t_stack *stack);
void	ft_update_cost(t_stack *stack_a, t_stack *stack_b);
void	ft_operation_aid(t_stack **stack_a, t_stack **stack_b, \
							int cheapest_option, int highest_low);
void	ft_operation(t_stack **stack_a, t_stack **stack_b, \
						int cheapest_option, int highest_low);
void	ft_operation_aid_back(t_stack **stack_b, t_stack **stack_a, \
								int cheapest_option, int highest_low);
void	ft_operation_back(t_stack **stack_b, t_stack **stack_a, \
							int cheapest_option, int highest_low);
void	ft_op_move(t_stack **stack_a, t_stack **stack_b, \
					t_stack *head_a, t_stack *head_b);
void	ft_op_move_back(t_stack **stack_a, t_stack **stack_b, \
							t_stack *head_a, t_stack *head_b);
void	ft_delete_lst_content(t_stack **stack);
void	ft_sorted_but_not_quite_aid(t_stack *stack_a);
void	ft_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	ft_b_to_a(t_stack **stack_b, t_stack **stack_a);
void	ft_full_push_swap(char **argv);

int		ft_is_stack_sorted(t_stack *stack);
int		ft_check_min(t_stack *stack);
int		ft_check_max(t_stack *stack);
int		ft_cost(t_stack *head_a, t_stack *head_b, int position);
int		ft_lowest_cost(int position_a, int position_b, int len_a, int len_b);
int		ft_stack_len(t_stack *stack);
int		ft_big_or_small(int num, t_stack *stack);
int		ft_highest_low(t_stack *stack, int num);
int		ft_lowest_high(t_stack *stack, int num);
int		ft_cheapest_option(t_stack *stack_a);
int		ft_sorted_but_not_quite(t_stack *stack_a);
int		ft_if_only_swap_two(t_stack *stack);
int		ft_if_only_swap_two_aid(t_stack *first_node, t_stack *second_node, \
									int checker, int num);
int		ft_check_target_pos(t_stack *stack);
int		ft_check_if_repeated_int(char **argv);


//bonus

typedef struct s_commands
{
	char				*command;
	struct s_commands	*next;
}	t_commands;

t_commands	*ft_push_swap_commands(int fd);
void	ft_checker(char	**argv, t_commands *commands);

#endif