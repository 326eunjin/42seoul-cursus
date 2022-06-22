/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:33:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/23 00:03:46 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minishell.h"

// 디버깅용
char *to_types[] = {"TO_COMMON", "TO_REDIRIN", "TO_REDIROUT", "TO_HEREDOC", "TO_APPEND", "PIPE", "DQUOTE", "QUOTE", "DOLLAR"};
char *cmd_types[] = {"COMMON", "REDIRIN", "REDIROUT", "HEREDOC", "APPEND", "REDIRARG", "BUILTIN", "OPTION"};

static void	free_cmd(t_cmd_line_list *cmd_line_list)
{
	t_cmd_node	*curr;
	t_cmd_node	*temp;
	int			idx;

	idx = 0;
	while (idx < cmd_line_list->size)
	{
		if (cmd_line_list->cmd_heads == NULL)
			break ;
		curr = cmd_line_list->cmd_heads[idx];
		while (curr != NULL)
		{
			temp = curr;
			if (curr->cmd != 0)
				free(curr->cmd);
			curr = curr->next;
			free(temp);
		}
		idx++;
	}
	free(cmd_line_list->cmd_heads);
	free(cmd_line_list);
	cmd_line_list = 0;
}

int	main(int argc, char **argv, char **envp)
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
		ft_memset(cmd_line_list, 0, sizeof(t_cmd_line_list));
		if (parse_cmd(&cmd_line_list) == FALSE)
		{
			free_cmd(cmd_line_list);
			continue ;
		}
		exe_cmd(cmd_line_list);
		free_cmd(cmd_line_list);
	}
	//free_envp(); // 환경변수 free
	return (0);
}
