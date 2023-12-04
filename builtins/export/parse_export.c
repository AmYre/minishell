/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:13:29 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/04 21:52:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

//launch export function as many times as number of commands
int main(int argc, char **argv, char **env)
{
	int i;
	char **new_testenv;

	i = 0;
	(void)argv;
	(void)argc;
	new_testenv = ft_export("lbarry=honey", env);
	while (new_testenv[i])
	{
		printf("%s\n", new_testenv[i]);
		free(new_testenv[i]);
		i++;
	}
	free(new_testenv);
	return (0);
}
