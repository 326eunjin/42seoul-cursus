/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:20:34 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/24 03:31:00 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	remove_temp_file(void)
{
	struct stat	s;

	if (stat("ejang.jeyoon", &s) ==0)
		unlink("ejang.jeyoon");
}

void	move_heredoc_curser(int fd)
{
	close(fd);
	ft_putstr_fd("\x1b[1A", 1);
	ft_putstr_fd("\033[2C", 1);
	exit(0);
}
