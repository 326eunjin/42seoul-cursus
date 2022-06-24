/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:34:04 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/25 04:18:52 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sigint_handler(int sig)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (sig == SIGINT)
	{
		if (pid == -1)
		{
			ft_putendl_fd("", STDOUT_FILENO);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_state.exit_status = 1;
		}
		else
		{
			g_state.exit_status = 130;
			ft_putendl_fd("", STDOUT_FILENO);
		}
	}
}

void	sigquit_handler(int sig)
{
	pid_t	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (sig == SIGQUIT)
	{
		if (pid == -1)
		{
			rl_on_new_line();
			rl_redisplay();
		}
		else
		{
			g_state.exit_status = 131;
			ft_putstr_fd("Quit: ", STDOUT_FILENO);
			ft_putnbr_fd(sig, STDOUT_FILENO);
			ft_putendl_fd("", STDOUT_FILENO);
		}
	}
}

void	sig_heredoc_handler(int sig)
{
	(void)sig;
	ft_putendl_fd("", STDOUT_FILENO);
	exit(130);
}
