/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:01:44 by tiaferna          #+#    #+#             */
/*   Updated: 2023/09/24 21:16:12 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line/get_next_line.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

char *ft_strdup(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }

    char *new_str = (char *)malloc((len + 1) * sizeof(char));

    if (new_str == NULL) {
        return NULL;
    }

    for (size_t i = 0; i <= len; i++) {
        new_str[i] = str[i];
    }
    return (new_str);
}

t_commands	*ft_push_swap_commands(int fd)
{
	t_commands	*commands = NULL;
	t_commands	*head = NULL;
	t_commands	*new_command = NULL;
	char 		*line;

	while (1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) <= 0)
			break;
		new_command = (t_commands *)malloc(sizeof(t_commands));
		new_command->command = ft_strdup(line);
		free(line);
		new_command->next = NULL;
		if (head == NULL)
		{
			head = new_command;
			commands = head;
		}
		else
		{
			commands->next = new_command;
			commands = commands->next;
		}
	}
	return (head);
}

void	ft_checker(char	**argv, t_commands *commands)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *next;

	stack_a = ft_create_stack(argv);
	stack_b = NULL;
	while (commands)
	{
		if (ft_strcmp(commands->command, "Error\n") == 0)
		{
			write(1, "Error\n", 6);
			return ;
		}
		else if (ft_strcmp(commands->command, "sa\n") == 0)
			ft_swap_top_two(&stack_a);
		else if (ft_strcmp(commands->command, "pa\n") == 0)
			ft_push_to_stack(&stack_b, &stack_a);
		else if (ft_strcmp(commands->command, "pb\n") == 0)
			ft_push_to_stack(&stack_a, &stack_b);
		else if (ft_strcmp(commands->command, "ra\n") == 0)
			ft_top_to_bottom(&stack_a);
		else if (ft_strcmp(commands->command, "rb\n") == 0)
			ft_top_to_bottom(&stack_b);
		else if (ft_strcmp(commands->command, "rr\n") == 0)
		{
			ft_top_to_bottom(&stack_a);
			ft_top_to_bottom(&stack_b);
		}
		else if (ft_strcmp(commands->command, "rra\n") == 0)
			ft_bottom_to_top(&stack_a);
		else if (ft_strcmp(commands->command, "rrb\n") == 0)
			ft_bottom_to_top(&stack_b);
		else if (ft_strcmp(commands->command, "rrr\n") == 0)
		{
			ft_bottom_to_top(&stack_a);
			ft_bottom_to_top(&stack_b);
		}
		commands = commands->next;
	}
	if (ft_is_stack_sorted(stack_a) == 0 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_a->prev->next = NULL;
	while (stack_a)
	{
		next = stack_a->next;
		ft_delete_lst_content(&stack_a);
		free(stack_a);
		stack_a = next;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int			i;
		int			fd;
		t_commands	*commands;
		t_commands	*head;

		if (argc == 1)
			return (0);
		i = 1;
		while (argv[i])
			if (ft_atol(argv[i++]) == 3333333333)
				return (write(1, "Error\n", 6));
		if (ft_check_if_repeated_int(argv) == 1)
			return (write(1, "Error\n", 6));
		fd = 0;
		commands = ft_push_swap_commands(fd);
		head = commands;
		ft_checker(argv, commands);
		while (head)
		{
			t_commands *temp = head;
			head = head->next;
			free(temp->command);
			free(temp);
		}
	}
	return (0);
}
