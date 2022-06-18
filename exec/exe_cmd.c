/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/18 14:47:50 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exe_cmd(t_cmd_line_list *cmd_line_list)
{
	int idx = -1;
	int j = 0;
	int fd[cmd_line_list->size-1][2];
	pid_t pid[cmd_line_list->size];
	int status[cmd_line_list->size];

	/////////////////cd exit 처리 부분
	if (cmd_line_list->size == 1)
	{
		if (ft_strcmp(cmd_line_list->cmd_heads[0]->cmd,"cd") == 0)
		{
			func_cd(cmd_line_list->cmd_heads[0]);
			return;
		}
		if (ft_strcmp(cmd_line_list->cmd_heads[0]->cmd,"exit") == 0)
		{
			func_exit_single_cmd(cmd_line_list->cmd_heads[0]);
			return;
		}
	}
	////////////////////
	while(++idx < cmd_line_list->size - 1)
		pipe(fd[idx]);
	idx = -1; 
	while (++idx < cmd_line_list->size)
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
	}
	//아마 close 다 하는 부분은 따로 함수로 빼야할듯 그럼 줄이 줄어들지 않을까싶다...
	for(int j = 0;j<cmd_line_list->size;j++)
		waitpid(pid[j],&status[j],0);
}

void	exe_single_cmd(t_cmd_node	*node)
{
	char **arg;
	char *tmp;
	if (is_cmd_builtin(node) == TRUE)
	{
		exe_builtin(node);
		//return ;
	}
	else
	{
		tmp = is_valid_cmd(node);
		
		arg = string_array(node);
		if (execve(tmp,arg,g_state.envp) == -1)
		{
			ft_putstr_fd("bash : ", STDERR_FILENO);
			ft_putstr_fd(node->cmd, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(1);
		}
	}
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

char*	is_valid_cmd(t_cmd_node *node)
{
	//node->cmd 명령어
	struct stat s;
	char **tmp = ft_split(get_value("PATH"),':');
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
		str = ft_strdup("/");
		str2 = ft_strdup(node->cmd);//ls
		str = ft_strjoin(str,str2);// /ls
		str2 = ft_strjoin(tmp[i],str);// /usr/bin/ls
		if (stat(str2, &s) == 0)
		{
			free(tmp);
			tmp = NULL;
			return (str2);
		}
		free(str2);
	}
	//printf("bash: %s: command not found\n",node->cmd);
	free(tmp);
	tmp = NULL;
	return (NULL);
}