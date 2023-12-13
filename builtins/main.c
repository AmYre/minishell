/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:29:38 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/13 19:30:39 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//create a function that will create a new node for each env variable
t_env *init_env(char **env)
{
	t_env *new_env;
	t_env *head;
	int i;
	char *key;
	char *value;

	i = 0;
	head = NULL;
	while (env[i])
	{
		new_env = malloc(sizeof(t_env));
		key = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		value = ft_substr(env[i], ft_strchr(env[i], '=') - env[i] + 1, ft_strlen(env[i]));
		new_env->key = key;
		new_env->value = value;
		new_env->next = head;
		head = new_env;
		i++;
	}
	return (head);
}

//MAIN de EXIT
// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	ft_exit(argv);

// 	return (0);
// }

//MAIN de ENV
int main(int argc, char **argv, char **env)
{
	t_env *ls_env;
	//t_env *tmp;

	(void)argv;
	(void)argc;
	ls_env = init_env(env);
	ft_env(argv, ls_env);
	// tmp = head;
	// while (tmp)
	// {
	// 	printf("%s=\"%s\"\n", tmp->key, tmp->value);
	// 	tmp = tmp->next;
	// }
	return (0);
}

//MAIN de EXPORT
// int main(int argc, char **argv, char **env)
// {
// 	int i;
// 	char **new_testenv;

// 	i = 0;
// 	(void)argv;
// 	(void)argc;
// 	new_testenv = ft_export("carson=aa\"    \' \"bb", env);
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
