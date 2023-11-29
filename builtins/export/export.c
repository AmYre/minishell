#include "../builtins.h"

int	ft_isexport(char *str)
{
	int i;

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
	while (str[i] != '=' && str[i])
		i++;
	name = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		name[j] = str[j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

char **ft_export(char *command, char **env)
{
	int i;
	char *name;
	int sign;

	i = 0;
	name = get_name(command);
	sign = ft_strchr(command, '=');
	if (ft_isexport(name))
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
			{
				free(env[i]);
				if (!sign)
				{
					env[i] = ft_strjoin(name, "=");
					return (env);
				}
				else
				{
					env[i] = command;
					return (env);
				}
				free(name);
			}
			i++;
		}
		if (!sign)
		{
			env[i] = ft_strjoin(name, "=");
			env[i + 1] = NULL;
		}
		else
		{
			env[i] = command;
			env[i + 1] = NULL;
		}
		free(name);
	}
	else
	{
		printf("export: '%s': not a valid identifier\n", name);
		free(name);
	}
	return (env);
}

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
	return (0);
}