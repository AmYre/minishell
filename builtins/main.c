/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:29:38 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 18:22:43 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	main(int argc, char **argv)
{
	(void)argc;
	ft_exit(argv);

	return (0);
}

// MAIN de EXPORT
// int main(int argc, char **argv, char **env)
// {
// 	int i;
// 	char **new_testenv;

// 	i = 0;
// 	(void)argv;
// 	(void)argc;
// 	new_testenv = ft_export("lbarry=honey", env);
// 	while (new_testenv[i])
// 	{
// 		printf("%s\n", new_testenv[i]);
// 		free(new_testenv[i]);
// 		i++;
// 	}
// 	free(new_testenv);
// 	return (0);
// }


// MAIN de UNSET
// int main(int argc, char **argv, char **env)
// {
// 	int i;
// 	char **new_env;
// 	char **unset_env;

// 	i = 0;
// 	(void)argv;
// 	(void)argc;
// 	new_env = ft_export("TEST=amir", env);
// 	while (new_env[i])
// 	{
// 		printf("%s\n", new_env[i]);
// 		i++;
// 	}
// 	unset_env = ft_unset("TEST", new_env);
// 	printf("\n");
// 	printf("--------------------\n");
// 	printf("\n");
// 	i = 0;
// 	while (unset_env[i])
// 	{
// 		printf("%s\n", unset_env[i]);
// 		free(unset_env[i]);
// 		i++;
// 	}
// 	free(unset_env);
// 	i = 0;
// 	while (new_env[i])
// 	{
// 		free(new_env[i]);
// 		i++;
// 	}
// 	free(new_env);
// 	return (0);
// }


// MAIN de ECHO
// int main (void)
// {
// 	char *command[] = {"echo", "-n", "hello", "my", "world", NULL};

// 	ft_echo(command);
// 	return (0);
// }
