/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:57 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/05 00:44:58 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

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

int main(int argc, char **argv, char **env)
{
	int i;
	char **new_env;
	char **unset_env;

	i = 0;
	(void)argv;
	(void)argc;
	new_env = ft_export("TEST=amir", env);
	while (new_env[i])
	{
		printf("%s\n", new_env[i]);
		i++;
	}
	unset_env = ft_unset("TEST", new_env);
	printf("\n");
	printf("--------------------\n");
	printf("\n");
	i = 0;
	while (unset_env[i])
	{
		printf("%s\n", unset_env[i]);
		free(unset_env[i]);
		i++;
	}
	free(unset_env);
	i = 0;
	while (new_env[i])
	{
		free(new_env[i]);
		i++;
	}
	free(new_env);
	return (0);
}