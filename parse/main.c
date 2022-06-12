/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:33:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/12 22:10:46 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// 디버깅용
char *to_types[] = {"TO_COMMON", "TO_REDIRIN", "TO_REDIROUT", "TO_HEREDOC", "TO_APPEND", "PIPE", "DQUOTE", "QUOTE"};
char *cmd_types[] = {"COMMON", "REDIRIN", "REDIROUT", "HEREDOC", "APPEND", "BUILTIN", "OPTION"};

int main(int argc, char **argv, char **envp)
{
	t_cmd_line_list *cmd_line_list;
	g_state.envp = copy_envp(envp);
	//환경 변수 불러오기
	// if (is_in_envp("OLDPWD") == -1)
	// 	add_old_pwd(); 만약에 OLDPWD 환경변수 없으면 추가하기
	while (1)
	{
		if (parse_cmd(&cmd_line_list) == FALSE)
		{
			//return_error(cmd_line);
			continue;
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

		//실행부분
		exe_cmd(cmd_line_list);
		int i = -1;
		while(g_state.envp[++i])
			printf("%s\n",g_state.envp[i]);
	}
	//ㄷ ㅏ실행하고 나서 전역 변수 환경변수 복사본 해제해줘야함.
	return (0);
}