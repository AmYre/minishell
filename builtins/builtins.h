/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:19:21 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/06 17:56:31 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

char	**ft_export(char *command, char **env);
char	**ft_unset(char *name, char **env);
void	ft_cd(char **args);
void	ft_echo(char **args);
void	ft_env(char **argv, char **env);
void	ft_pwd(void);
void	ft_exit(char **argv);

#endif