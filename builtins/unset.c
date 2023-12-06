/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:57 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 17:58:39 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char **ft_unset(char *name, char **env)
{
	int 	i;
	int 	len;
	int 	found_match;
	char	*signed_name;
	char 	**new_env;

	i = 0;
	len = 0;
	found_match = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
			found_match = 1;
		i++;
	}
	if (!found_match)
		return (env);
	signed_name = ft_strjoin(name, "=");
	new_env = malloc(sizeof(char *) * i);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], signed_name, ft_strlen(name) + 1) != 0)
			new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i -1] = NULL;
	free(signed_name);
	return (new_env);
}
