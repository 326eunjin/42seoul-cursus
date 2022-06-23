/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:21:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/23 14:26:39 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	set_exec_signal(void)
{
	signal(SIGINT, sigint_exec_handler);
	signal(SIGQUIT, sigquit_exec_handler);
}

void	set_heredoc_signal(void)
{
	signal(SIGINT, sig_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	set_main_signal(void)
{
	signal(SIGINT, sig_main_handler);
	signal(SIGQUIT, SIG_IGN);
}
