/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_with_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:35:45 by ejang             #+#    #+#             */
/*   Updated: 2022/06/23 11:28:39 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	malloc_fd(int size, int ***fd)
{
	int	i;

	i = 0;
	*fd = (int **)malloc(sizeof(int *) * size);
	if (*fd == NULL)
		return (FALSE);
	ft_memset(*fd, 0, sizeof(*fd));
	while (i < size)
	{
		(*fd)[i] = (int *)malloc(sizeof(int) * 2);
		if ((*fd)[i] == NULL)
			return (FALSE);
		ft_memset((*fd)[i], 0, sizeof((*fd)[i]));
		i++;
	}
	return (TRUE);
}

void	exe_with_pipe(t_cmd_line_list *cmd_line_list)
{
	int		idx;
	int		j;
	int		**fd;
	pid_t	pid[cmd_line_list->size];
	int		status[cmd_line_list->size];

	idx = -1;
	j = 0;
	if (malloc_fd(cmd_line_list->size - 1, &fd) == FALSE)
	{
		g_state.exit_status = 1;
		exit(1);
	}
	set_exec_signal();
	while (++idx < cmd_line_list->size - 1)
		pipe(fd[idx]);
	idx = -1;
	while (++idx < cmd_line_list->size)
	{
		pid[idx] = fork();
		if (pid[idx] < 0) // fork error
			g_state.exit_status = 1;
		else if (pid[idx] == 0)
		{
			if (idx > 0)
				dup2(fd[idx - 1][0], STDIN_FILENO);
			if (idx < cmd_line_list->size - 1)
				dup2(fd[idx][1], STDOUT_FILENO);
			exe_single_cmd_with_pipe(cmd_line_list->cmd_heads[idx], &fd, cmd_line_list->size);
			g_state.exit_status = 1;
		}
	}
	for (int j = 0; j < cmd_line_list->size - 1; j++)
	{
		close(fd[j][0]);
		close(fd[j][1]);
	}
	for (int j = 0; j < cmd_line_list->size; j++)
		waitpid(pid[j], &status[j], 0);
}

void	exe_single_cmd_with_pipe(t_cmd_node *node, int ***fd, int size)
{
	char		**arg;
	char		*tmp;
	t_cmd_node	*cmd_list;

	redir_in(node);
	redir_out(node);
	cmd_list = remove_redir(node);
	//close_fd(*fd, size);
	for (int i = 0; i < size - 1; i++)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
	}
	if (cmd_list->type == BUILTIN)
		exe_builtin(cmd_list);
	else
	{
		tmp = is_valid_cmd(cmd_list);
		arg = string_array(cmd_list);
		if (execve(tmp, arg, g_state.envp) == -1)
		{
			ft_putstr_fd("bash : ", STDERR_FILENO);
			ft_putstr_fd(node->cmd, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(1);
		}
	}
	// free는 도대체 어디서 해야할까,,,이거 pipex에서 했던 고민이랑 같음.
}
