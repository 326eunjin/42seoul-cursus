/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_with_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:35:45 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 21:35:44 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	close_fd(int ***fd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
		i++;
	}
}

static void	close_wait(int ***fd, pid_t **pid, int *status, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		waitpid((*pid)[i], &status[i], 0);
		g_state.exit_status = status[i] / 256;
		i++;
	}
}

static void	exe_single_cmd_with_pipe(t_cmd_node *node, int ***fd, int size)
{
	char		**arg;
	char		*tmp;
	t_cmd_node	*cmd_list;

	redir_in(node);
	redir_out(node);
	cmd_list = remove_redir(node);
	close_fd(fd, size - 1);
	if (cmd_list->type == BUILTIN)
		exe_builtin(cmd_list);
	else
	{
		tmp = is_valid_cmd(cmd_list);
		arg = string_array(cmd_list);
		if (execve(tmp, arg, g_state.envp) == -1)
			execve_error(strerror(errno),cmd_list);
	}
}

static void	pipe_process(int size, int ***fd)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		pipe((*fd)[i]);
		i++;
	}
}

void	exe_with_pipe(t_cmd_line_list *list)
{
	int		idx;
	int		**fd;
	pid_t	*pid;
	int		*status;

	malloc_variables(list->size, &fd, &pid, &status);
	set_exec_signal();
	pipe_process(list->size, &fd);
	idx = -1;
	while (++idx < list->size)
	{
		pid[idx] = fork();
		if (pid[idx] < 0)
			exit(1);
		else if (pid[idx] == 0)
		{
			if (idx > 0)
				dup2(fd[idx - 1][0], STDIN_FILENO);
			if (idx < list->size - 1)
				dup2(fd[idx][1], STDOUT_FILENO);
			exe_single_cmd_with_pipe(list->cmd_heads[idx], &fd, list->size);
		}
	}
	close_wait(&fd, &pid, status, list->size);
	free_array(fd, list->size - 1);
	free(pid);
	pid = NULL;
	free(status);
	status = NULL;
}
