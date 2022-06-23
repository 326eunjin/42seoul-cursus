/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:04:20 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 02:54:06 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	get_redir_in(t_cmd_node *node)
{
	t_cmd_node	*curr;
	int			cnt;

	cnt = 0;
	curr = node;
	while (curr != NULL)
	{
		if (curr->type == REDIRIN)
			cnt++;
		curr = curr->next;
	}
	return (cnt);
}

static void	do_redir(char *cmd, int flag)
{
	struct stat	file_info;

	if ((stat(cmd, &file_info) == -1) && (flag == FALSE))
	{
		flag = TRUE;
		ft_putstr_fd("bash: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit(1);
	}
}

char	*has_redir_in(t_cmd_node *node)
{
	t_cmd_node	*last_redirin;
	int			flag;
	struct stat	file_info;
	int			cnt;

	flag = FALSE;
	cnt = get_redir_in(node);
	if (cnt == 0)
		return (NULL);
	while (node != NULL)
	{
		if (node->type == REDIRIN)
		{
			do_redir(node->next->cmd, flag);
			last_redirin = node;
		}
		node = node->next;
	}
	return (last_redirin->next->cmd);
}

void	redir_in(t_cmd_node *node)
{
	char	*infile;
	int		in_fd;

	infile = has_redir_in(node);
	if (infile != NULL)
	{
		in_fd = open(infile, O_RDWR | O_CREAT, 0644);
		if (in_fd < 0)
		{
			ft_putstr_fd("fd error\n", STDERR_FILENO);
			exit(1);
		}
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
}
