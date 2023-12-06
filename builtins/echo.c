/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:51:06 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 17:58:48 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "builtins.h"

int check_n_flag(char *str)
{
	int i;
	int len;

	i = 2;
	len = ft_strlen(str);
	if (str[0] == '-' && str[1] == 'n')
	{
		if (len == 2)
			return (1);
		else
		{
			while (str[i] == 'n')
			i++;
		}
		if (i == len)
		return (1);
	}
	return (0);
}

void	ft_echo(char **args)
{
	int i;
	int n_flag;

	n_flag = 0;
	if (args[1] == NULL)
	{
		printf("\n");
		return ;
	}
	n_flag = check_n_flag(args[1]);
	if (n_flag == 1)
	{
		i = 2;
		while ( i < ft_arrlen(args))
		{
			if (i == ft_arrlen(args) - 1)
				printf("%s", args[i]);
			else
				printf("%s ", args[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		while ( i < ft_arrlen(args))
		{
			if (i == ft_arrlen(args) - 1)
				printf("%s\n", args[i]);
			else
				printf("%s ", args[i]);
			i++;
		}
	}
	return ;
}

