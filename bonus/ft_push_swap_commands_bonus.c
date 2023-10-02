/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_commands_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:15:09 by tiago             #+#    #+#             */
/*   Updated: 2023/10/02 10:53:23 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_commands	*ft_push_swap_commands(int fd)
{
	t_commands	*head;
	t_commands	*tail;
	t_commands	*new_command;
	char		*line;

	head = NULL;
	tail = NULL;
	line = get_next_line(fd);
	while (ft_strlen(line) > 0)
	{
		new_command = (t_commands *)malloc(sizeof(t_commands));
		new_command->command = ft_strdup(line);
		new_command->next = NULL;
		if (!head)
			head = new_command;
		else
			tail->next = new_command;
		tail = new_command;
		line = get_next_line(fd);
	}
	return (head);
}
