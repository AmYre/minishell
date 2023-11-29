/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:53:59 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/18 22:49:50 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//test the readline function
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

void	sig_handler(int signo)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

//ORDER OF PARSING FOR MINISHELL
//Is there any pipes?
//Is there any redirections?
//Command is a builtin?


int main()
{
	signal(SIGINT, sig_handler);
	char *line;
	while (1)
	{
		line = readline("minish> ");
		if (!line)
			break;
		if (*line)
			add_history(line);

		free(line);
	}
	return (0);
}