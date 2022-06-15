/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/15 17:22:25 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//void	exe_cmd(t_cmd_line_list *cmd_line_list)
void	exe_builtin(t_cmd_node	*node)
{

	if (ft_strcmp(node->cmd,"pwd") == 0)
		func_pwd();
	if (ft_strcmp(node->cmd, "env") == 0)
		func_env();
	if (ft_strcmp(node->cmd,"echo") == 0)
		func_echo(node);
	if (ft_strcmp(node->cmd,"export") == 0)
		func_export(node);
	if (ft_strcmp(node->cmd,"unset") == 0)
		func_unset(node);
	if (ft_strcmp(node->cmd, "cd") == 0)
		func_cd(node);
}

void	exe_cmd(t_cmd_line_list *cmd_line_list)
{
	int idx = 0;
	int j = 0;

	int fd[cmd_line_list->size-1][2];
	pid_t pid[cmd_line_list->size];
	int status[cmd_line_list->size];
	while(idx < cmd_line_list->size - 1)
	{
		pipe(fd[idx]);
		idx++;
	}
	idx = 0;
	while (idx < cmd_line_list->size)
	{
		pid[idx] = fork();
		if (pid[idx] < 0)//fork error
			g_state.exit_status = 1;
		else if (pid[idx] == 0)//child process
		{
			if (idx > 0)
				dup2(fd[idx-1][0], STDIN_FILENO);
			if (idx < cmd_line_list->size - 1)
				dup2(fd[idx][1],STDOUT_FILENO);
			while(j<cmd_line_list->size - 1)
			{
				close(fd[j][0]);
				close(fd[j][1]);
				j++;
			}
			//실행 함수 호출
			exe_single_cmd(cmd_line_list->cmd_heads[idx]);
			g_state.exit_status = 1;
		}
		else//parent process
		{
			if (idx == cmd_line_list->size - 1)
			{
				for(int j = 0;j<cmd_line_list->size - 1;j++)
				{
					close(fd[j][0]);
					close(fd[j][1]);
				}
			}
		}
		idx++;
	}
	for(int j = 0;j<cmd_line_list->size;j++)
		waitpid(pid[j],&status[j],0);
}

void	exe_single_cmd(t_cmd_node	*node)
{
	char **arg;
	arg = string_array(node);
	execve(arg[0],arg,g_state.envp);
	//free는 도대체 어디서 해야할까,,,
	//이거 pipex에서 했던 고민이랑 같음. 
}

char	**string_array(t_cmd_node *node)
{
	t_cmd_node *curr = node;
	char **ret;
	int cnt = 0;
	int i = 0;
	while (curr != NULL)
	{
		cnt++;
		curr=curr->next;
	}
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	curr = node;
	while(i<cnt)
	{
		ret[i] = ft_strdup(curr->cmd);
		curr = curr->next;
		i++;
	}
	ret[cnt] = NULL;
	return (ret);
}