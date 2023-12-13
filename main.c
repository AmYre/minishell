/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:53:59 by amben-ha          #+#    #+#             */
/*   Updated: 2023/12/08 19:14:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

void	sig_handler(int signo)
{
	if (signo == SIGINT)
		printf("received signal %d\n", signo);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(void)
{
	char				*line;

	signal(SIGINT, sig_handler);
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

//TO DO
// try to exec a command coming from readline without the parsing
// handle exits status, even when contro D/C is pressed