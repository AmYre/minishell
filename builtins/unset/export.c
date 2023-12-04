/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:45:50 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/05 00:11:33 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void free_all(char *name, char *value, char *signed_name)
{
	free(name);
	free(value);
	free(signed_name);
}

int	is_export(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] <= '9' && str[i] >= '0')
			|| (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
		{
			if (i == 0 && str[i] >= '0' && str[i] <= '9')
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char *get_name(char *str)
{
	int i;
	int j;
	char *name;

	i = 0;
	j = 0;
	if (str[0] == '=')
		return (str);
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] != '=')
		return (NULL);
	if (str[i-1] == '+')
		i--;
	name = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		name[j] = str[j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

char *get_value(char *str)
{
	int i;
	int j;
	int sign;
	char *value;

	i = 0;
	j = 0;
	sign = 0;
	if (str[0] == '=')
		return (str);
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '=')
		i++;
	j = i;
	while (str[j])
		j++;
	value = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i])
	{
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}

int ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int check_match(char *signed_name, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], signed_name, ft_strlen(signed_name)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char **ft_export(char *command, char **env)
{
	int		i;
	int		j;
	int		sign;
	int		found_match;
	char	*name;
	char	*value;
	char	*signed_name;
	char	**new_env;
	char	*exec_env[2];

	i = 0;
	j = 0;
	exec_env[0] = "env";
	exec_env[1] = NULL;
	if (!command)
	{
		while (env[i])
		{
			printf("export %s\n", env[i]);
			i++;
		}
		return (env);
	}
	name = get_name(command);
	if (!name)
		return (env);
	value = get_value(command);
	if (!value)
		value = "";
	signed_name = ft_strjoin(name, "=");
	sign = ft_strchr_sign(command, '=');
	found_match = check_match(signed_name, env);
	if (found_match)
		new_env = malloc(sizeof(char *) * (ft_arrlen(env) + 1));
	else
		new_env = malloc(sizeof(char *) * (ft_arrlen(env) + 2));
	if (is_export(name))
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], signed_name, ft_strlen(signed_name)) == 0)
			{
				if (sign == 2)
					new_env[i] = ft_strjoin(env[i], value);
				else
					new_env[i] = ft_strdup(command);
			}
			else
			{
				new_env[i] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
				int j = 0;
				while (env[i][j])
				{
					new_env[i][j] = env[i][j];
					j++;
				}
				new_env[i][j] = '\0';
			}
			i++;
		}
		if (!found_match)
		{
			if (!sign)
				new_env[i] = signed_name;
			else if (sign == 2)
				new_env[i] = ft_strjoin(signed_name, value);
			else
				new_env[i] = ft_strdup(command);
			new_env[i + 1] = NULL;
		}
		else
			new_env[i] = NULL;
	}
	else
		printf("export: '%s': not a valid identifier\n", name);
	free_all(name, value, signed_name);
	return (new_env);
}
