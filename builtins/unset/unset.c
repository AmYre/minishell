/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:57 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/29 18:40:50 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int main(int argc, char **argv, char **env)
{
	int i;
	char **new_env;

	i = 0;
	(void)argv;
	(void)argc;
	new_env = ft_export("TEST=amir", env);
	while (new_env[i])
	{
		printf("%s\n", new_env[i]);
		i++;
	}
	ft_unset("TEST", new_env);
	printf("\n");
	printf("--------------------\n");
	printf("\n");
	i = 0;
	while (new_env[i])
	{
		printf("%s\n", new_env[i]);
		i++;
	}
	return (0);
}