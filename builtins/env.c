/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:26:12 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/13 19:21:57 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "builtins.h"

void	ft_env(char **argv, t_env *env)
{
	t_env *current;
	int i;

	i = 0;
	current = env;
	if (argv[1])
	{
		printf("env: %s: No such file or directory\n", argv[1]);
		return ;
	}
	while (current)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}
