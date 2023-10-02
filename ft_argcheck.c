/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:52:47 by tiaferna          #+#    #+#             */
/*   Updated: 2023/10/02 10:55:44 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_argcheck(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], NULL) || !ft_strcmp(argv[i], "-") \
				|| !ft_strcmp(argv[i], "+"))
			return (0);
		i++;
	}
	return (1);
}
