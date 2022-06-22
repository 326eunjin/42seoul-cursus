/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:25:50 by ejang             #+#    #+#             */
/*   Updated: 2022/06/22 22:37:41 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_cmd_node *has_redir_out(t_cmd_node *node)
{
	t_cmd_node *curr = node;
	t_cmd_node *last_redirout = NULL;
	struct stat s;
	int fd;
	while (curr != NULL)
	{
		if (curr->type == REDIROUT)
		{
			if (stat(curr->next->cmd, &s) == 0) // redirout 뒤 파일명이 이미 있음 그럼 내용 삭제
			{
				fd = open(curr->next->cmd, O_RDWR | O_TRUNC, 0644);
				ft_putchar_fd(fd, STDERR_FILENO);
				if (fd < 0)
					ft_putstr_fd("FD ERROR\n", STDERR_FILENO);
				close(fd);
			}
			else //파일 명이 없음, 그러면 그냥 파일만 생성.
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
			//이미 있으면 아무것도 안함.
			if (stat(curr->next->cmd, &s) != 0) // append 뒤 파일명이 없음 그러면 생성만 함 내용 없음
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
	if (outfile != NULL) //노드에 REDIROUT이 있으면 <
	{
		if (outfile->type == REDIROUT)
			out_fd = open(outfile->next->cmd, O_RDWR, 0644); //이미 위에서 생성 및 삭제를 다 했기 때문에 dup2로 바꿔주기만 하면 된다.
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