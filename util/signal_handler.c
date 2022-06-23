/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:34:04 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/23 14:28:28 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	sig_main_handler(int sig)
{
	(void)sig;
	g_state.exit_status = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigint_exec_handler(int sig)
{
	(void)sig;
	g_state.exit_status = 130;
	ft_putendl_fd("", STDOUT_FILENO);
}

void	sigquit_exec_handler(int sig)
{
	ft_putstr_fd("Quit: ", STDOUT_FILENO);
	ft_putnbr_fd(sig, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	g_state.exit_status = 131;
}

void	sig_heredoc_handler(int sig)
{
	(void)sig;
	g_state.exit_status = 130;
	ft_putendl_fd("", STDOUT_FILENO);
	exit(130);
}
