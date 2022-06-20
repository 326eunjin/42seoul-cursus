/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/20 20:29:57 by ejang            ###   ########.fr       */
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
	char *outfile = NULL;
	t_cmd_node *curr = node;
	int in_fd;

	while (curr->type != BUILTIN && curr->type != COMMON)
		curr = curr->next;
	infile = has_redir_in(node);
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
		free(tmp);
		tmp = without_redir(node);
		//리다이렉션 빼고 명ㄹㅇ어를 만들어서 넘겨주면 되잖아요
	}
	// if (otufile != NULL)//노드에 REDIROUT이 있으면 >
	//	dup2(output, fd_out);	if (size > 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			close((*fd)[i][0]);
			close((*fd)[i][1]);
		}
	}
	if (curr->type == BUILTIN)
	{
		exe_builtin(curr);
		return;
	}
	else
	{

		if (tmp == NULL)//redirection 없음 
			tmp = is_valid_cmd(curr);
		else
			tmp = is_valid_cmd_redir(tmp);
		arg = ft_split(without_redir(curr),' ');
		if (execve(tmp, arg, g_state.envp) == -1)
		{
			ft_putstr_fd("bash : ", STDERR_FILENO);
			ft_putstr_fd(node->cmd, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(1);
		}
	}
	// free는 도대체 어디서 해야할까,,,
	//이거 pipex에서 했던 고민이랑 같음.
}

// char **string_array(t_cmd_node *node)
// {
// 	t_cmd_node *curr = node;
// 	char **ret;
// 	int cnt = 0;
// 	int i = 0;
// 	while (curr != NULL && curr->type != REDIROUT)
// 	{
// 		cnt++;
// 		curr = curr->next;
// 	}
// 	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
// 	curr = node;
// 	while (i < cnt)
// 	{
// 		ret[i] = ft_strdup(curr->cmd);
// 		curr = curr->next;
// 		i++;
// 	}
// 	ret[cnt] = NULL;
// 	return (ret);
// }

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
		str = ft_strjoin(ft_strdup("/"),ft_strdup(node->cmd));	// /ls
		str2 = ft_strjoin(ft_strdup(tmp[i]), str); // /usr/bin/ls
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
