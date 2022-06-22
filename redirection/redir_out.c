/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:25:50 by ejang             #+#    #+#             */
/*   Updated: 2022/06/22 23:12:33 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd_node	*has_redir_out(t_cmd_node *node)
{
	t_cmd_node	*curr;
	t_cmd_node	*last_redirout;
	struct stat	s;
	int			fd;

	curr = node;
	last_redirout = NULL;
	while (curr != NULL)
	{
		if (curr->type == REDIROUT)
		{
			if (stat(curr->next->cmd, &s) == 0)
			{
				fd = open(curr->next->cmd, O_RDWR | O_TRUNC, 0644);
				ft_putchar_fd(fd, STDERR_FILENO);
				if (fd < 0)
					ft_putstr_fd("FD ERROR\n", STDERR_FILENO);
				close(fd);
			}
			else
			{
				fd = open(curr->next->cmd, O_RDWR | O_CREAT, 0644);
				if (fd < 0)
					ft_putstr_fd("FD ERROR\n", STDERR_FILENO);
				close(fd);
			}
			last_redirout = curr;
		}
		else if (curr->type == APPEND)
		{
			if (stat(curr->next->cmd, &s) != 0)
			{
				fd = open(curr->next->cmd, O_RDWR | O_CREAT, 0644);
				if (fd < 0)
					ft_putstr_fd("FD ERROR\n", STDERR_FILENO);
				close(fd);
			}
			last_redirout = curr;
		}
		curr = curr->next;
	}
	return (last_redirout);
}

void	redir_out(t_cmd_node *node)
{
	t_cmd_node	*outfile;
	int			out_fd;

	outfile = has_redir_out(node);
	if (outfile != NULL)
	{
		if (outfile->type == REDIROUT)
			out_fd = open(outfile->next->cmd, O_RDWR, 0644);
		else
			out_fd = open(outfile->next->cmd, O_RDWR | O_APPEND, 0644);
		if (out_fd < 0)
		{
			ft_putstr_fd("fd error\n", STDERR_FILENO);
			g_state.exit_status = 1;
		}
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}