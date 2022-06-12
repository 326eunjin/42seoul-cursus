/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:21:28 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/12 21:20:33 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_echo_option(char *str)
{
	int idx;

	idx = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] != 'n')
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static void	check_builtin_cmd(t_cmd_node **curr_cmd)
{
	if (ft_strcmp((*curr_cmd)->cmd, "echo") == 0)
	{
		(*curr_cmd)->type = BUILTIN;
		if ((*curr_cmd)->next != NULL && (*curr_cmd)->next->cmd[0] == '-')
		{
			if (is_echo_option((*curr_cmd)->next->cmd) == TRUE)
			{
				*curr_cmd = (*curr_cmd)->next;
				(*curr_cmd)->type = OPTION;
			}
		}
	}
	else if (ft_strcmp((*curr_cmd)->cmd, "cd") == 0)
		(*curr_cmd)->type = BUILTIN;
	else if (ft_strcmp((*curr_cmd)->cmd, "pwd") == 0)
		(*curr_cmd)->type = BUILTIN;
	else if (ft_strcmp((*curr_cmd)->cmd, "export") == 0)
		(*curr_cmd)->type = BUILTIN;
	else if (ft_strcmp((*curr_cmd)->cmd, "unset") == 0)
		(*curr_cmd)->type = BUILTIN;
	else if (ft_strcmp((*curr_cmd)->cmd, "env") == 0)
		(*curr_cmd)->type = BUILTIN;
	else if (ft_strcmp((*curr_cmd)->cmd, "exit") == 0)
		(*curr_cmd)->type = BUILTIN;
}

void	check_cmd_type(t_cmd_node **cmd_heads, int size)
{
	int	idx;
	int	cmd_flag;
	t_cmd_node *curr_cmd;

	idx = 0;
	cmd_flag = 0;
	while (idx < size)
	{
		curr_cmd = cmd_heads[idx];
		while (curr_cmd != NULL)
		{
			// 여기서 먼저 리다이렉션 관련해서 예외처리 해 줘야 합니다.
			check_builtin_cmd(&curr_cmd);
			curr_cmd = curr_cmd->next;
		}
		idx++;
	}
}