/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:07:39 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 18:19:01 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_exit(char **argv)
{
	int i;

	i = 0;
	if (!argv[1])
		exit(0);
	if (argv[1])
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
				i++;
			else
			{
				printf("exit: %s: numeric argument required\n", argv[1]);
				exit(255);
			}
		}
		exit(ft_atoi(argv[1]));
	}
	exit(0);
}
