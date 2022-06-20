/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/21 01:21:30 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int malloc_fd(int size, int ***fd)
{
	int i;
	*fd = (int **)malloc(sizeof(int *) * size);
	if (*fd == NULL)
		return (FALSE);
	ft_memset(*fd, 0, sizeof(*fd));
	i = 0;
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

void exe_cmd(t_cmd_line_list *cmd_line_list)
{
	int idx = -1;
	int j = 0;
	int **fd;

	pid_t pid[cmd_line_list->size];
	int status[cmd_line_list->size];

	if (malloc_fd(cmd_line_list->size - 1, &fd) == FALSE)
	{
		g_state.exit_status = 1;
		exit(1);
	}
	/////////////////cd exit 처리 부분
	if (cmd_line_list->size == 1)
	{
		if (ft_strcmp(cmd_line_list->cmd_heads[0]->cmd, "cd") == 0)
		{
			func_cd(cmd_line_list->cmd_heads[0]);
			return;
		}
		if (ft_strcmp(cmd_line_list->cmd_heads[0]->cmd, "exit") == 0)
		{
			func_exit_single_cmd(cmd_line_list->cmd_heads[0]);
			return;
		}
	}
	////////////////////
	while (++idx < cmd_line_list->size - 1)
		pipe(fd[idx]);
	idx = -1;
	while (++idx < cmd_line_list->size)
	{
		pid[idx] = fork();
		if (pid[idx] < 0) // fork error
			g_state.exit_status = 1;
		else if (pid[idx] == 0) // child process
		{
			if (idx > 0) // in 바꿈
				dup2(fd[idx - 1][0], STDIN_FILENO);
			if (idx < cmd_line_list->size - 1)
				dup2(fd[idx][1], STDOUT_FILENO);
			exe_single_cmd(cmd_line_list->cmd_heads[idx], &fd, cmd_line_list->size);
			g_state.exit_status = 1;
		}
		else // parent process
		{
			if (idx == cmd_line_list->size - 1)
			{
				for (int j = 0; j < cmd_line_list->size - 1; j++)
				{
					close(fd[j][0]);
					close(fd[j][1]);
				}
			}
		}
	}
	//아마 close 다 하는 부분은 따로 함수로 빼야할듯 그럼 줄이 줄어들지 않을까싶다...
	for (int j = 0; j < cmd_line_list->size; j++)
		waitpid(pid[j], &status[j], 0);
}

void exe_single_cmd(t_cmd_node *node, int ***fd, int size)
{
	char **arg;
	char *tmp = NULL;
	char *infile = NULL;
	t_cmd_node *outfile = NULL;
	t_cmd_node *curr = node;
	int in_fd;
	int out_fd;
	t_cmd_node	*cmd_list = NULL;

	while (curr->type != BUILTIN && curr->type != COMMON)
		curr = curr->next;
	infile = has_redir_in(node);
	outfile = has_redir_out(node);
	if (infile != NULL) //노드에 REDIRIN이 있으면 <
	{
		in_fd = open(infile, O_RDWR | O_CREAT, 0644);
		if (in_fd < 0)
		{
			ft_putstr_fd("fd error\n", STDERR_FILENO);
			g_state.exit_status = 1;
		}
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
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
	if (infile != NULL || outfile != NULL)
		tmp = without_redir(node);
	if (infile != NULL || outfile != NULL)
		cmd_list = remove_redir(node);
	// ************** 확인용 프린트 **************
	t_cmd_node *haha;
	int hoho = 1;
	haha = cmd_list;
	ft_putstr_fd("****** new_list ******\n", STDERR_FILENO);
	while(haha != NULL)
	{
		ft_putnbr_fd(hoho, STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd(haha->cmd, STDERR_FILENO);
		haha = haha->next;
		hoho++;
	}
	ft_putstr_fd("**********************\n", STDERR_FILENO);
	// *****************************************
	for (int i = 0; i < size - 1; i++)
	{
		close((*fd)[i][0]);
		close((*fd)[i][1]);
	}
	if (curr->type == BUILTIN)
	{
		exe_builtin(curr);
		return;
	}
	else
	{

		if (tmp == NULL) // redirection 없음
			tmp = is_valid_cmd(curr);
		else
			tmp = is_valid_cmd_redir(tmp);
		arg = ft_split(without_redir(curr), ' ');
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

char *is_valid_cmd(t_cmd_node *node)
{
	// node->cmd 명령어
	struct stat s;
	char **tmp = ft_split(get_value("PATH"), ':');
	int i = -1;
	char *str;
	char *str2;

	if (stat(node->cmd, &s) == 0)
	{
		free_split(tmp);
		str = ft_strdup(node->cmd);
		return (str);
	}
	while (tmp[++i])
	{
		str = ft_strjoin(ft_strdup("/"), ft_strdup(node->cmd)); // /ls
		str2 = ft_strjoin(ft_strdup(tmp[i]), str);				// /usr/bin/ls
		if (stat(str2, &s) == 0)
		{
			free_split(tmp);
			tmp = NULL;
			return (str2);
		}
		free(str2);
	}
	// printf("bash: %s: command not found\n",node->cmd);
	free(tmp);
	tmp = NULL;
	return (NULL);
}
