/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:33:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/18 20:24:11 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// 디버깅용
char *to_types[] = {"TO_COMMON", "TO_REDIRIN", "TO_REDIROUT", "TO_HEREDOC", "TO_APPEND", "PIPE", "DQUOTE", "QUOTE", "DOLLAR"};
char *cmd_types[] = {"COMMON", "REDIRIN", "REDIROUT", "HEREDOC", "APPEND", "REDIRARG", "BUILTIN", "OPTION"};

static void	free_cmd(t_cmd_line_list *cmd_line_list)
{
	t_cmd_node	*curr;
	int			idx;

	idx = 0;
	while (idx < cmd_line_list->size)
	{
		curr = cmd_line_list->cmd_heads[idx];
		while (curr != NULL)
		{
			if (curr->cmd != 0)
				free(curr->cmd);
			free(curr);
			curr = curr->next;
		}
		idx++;
	}
	free(cmd_line_list->cmd_heads);
	free(cmd_line_list);
	cmd_line_list = 0;
}

int main(int argc, char **argv, char **envp)
{
	t_cmd_line_list	*cmd_line_list;

	rl_catch_signals = 0;
	set_signal();
	g_state.envp = copy_envp(envp);
	if (is_in_envp("OLDPWD") == -1)
		add_old_pwd();// 만약에 OLDPWD 환경변수 없으면 추가하기
	while (1)
	{
		cmd_line_list = (t_cmd_line_list *)malloc(sizeof(t_cmd_line_list));
		if (cmd_line_list == NULL)
			return (parse_error(2));
		if (parse_cmd(&cmd_line_list) == FALSE)
		{
			free_cmd(cmd_line_list);
			continue ;
		}
		// *** 디버깅용 프린트
 		t_cmd_node *curr_cmd;
 		for(int i = 0; i < cmd_line_list->size; i++)
 		{
 			curr_cmd = cmd_line_list->cmd_heads[i];
 			printf("#%d\n", i);
 			while(curr_cmd != NULL)
 			{
 				printf("cmd : %s (type : %s)\n", curr_cmd->cmd, cmd_types[curr_cmd->type]);
 				curr_cmd = curr_cmd->next;
 			}
 			printf("----\n");
 		}
 		// *** 끝
		exe_cmd(cmd_line_list);
		//exe_builtin(cmd_line_list->cmd_heads[0]);
		// // *** 디버깅용 프린트 (OLDPWD, PWD)
		int i = -1;
		// while(g_state.envp[++i])
		// 	if(ft_strncmp(g_state.envp[i],"OLDPWD",6) == 0 || ft_strncmp(g_state.envp[i],"PWD",3)== 0)
		// 		printf("%s\n",g_state.envp[i]);
		// *** 끝
		free_cmd(cmd_line_list);
	}
	//free_envp(); // 환경변수 free
	return (0);
}
