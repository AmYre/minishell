/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:50:53 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 17:58:58 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "builtins.h"

void	ft_cd(char **args)
{
	char *path;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			printf("minish: cd: HOME not set\n");
			return ;
		}
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		printf("minish: cd: %s: No such file or directory\n", path);
		return ;
	}
}

