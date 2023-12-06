/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:26:12 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 17:58:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "builtins.h"

void	ft_env(char **argv, char **env)
{
	int i;

	i = 0;
	if (argv[1])
	{
		printf("env: %s: No such file or directory\n", argv[1]);
		return ;
	}
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
