/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:12:59 by tiago             #+#    #+#             */
/*   Updated: 2023/09/30 22:15:12 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../push_swap.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_commands
{
	char				*command;
	struct s_commands	*next;
}	t_commands;

t_commands	*ft_push_swap_commands(int fd);

void		ft_checker(char	**argv, t_commands *commands);
void		ft_free_stack(t_stack *stack);
void		ft_double_top_to_bottom(t_stack **stack_a, t_stack **stack_b);
void		ft_double_bottom_to_top(t_stack **stack_a, t_stack **stack_b);

int			ft_command_action(t_commands *commands, \
								t_stack **stack_a, t_stack **stack_b);
int			ft_strcmp(char *str1, char *str2);

char		*ft_strdup(char *str);

#endif