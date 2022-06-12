/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/12 21:49:41 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exe_cmd(t_cmd_line_list *cmd_line_list)
{
	int	idx;

	idx = 0;
	while (idx < cmd_line_list->size)
	{
		if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "pwd") == 0)
			func_pwd();
		if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "env") == 0)
			func_env();
		if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "echo") == 0)
			func_echo(cmd_line_list->cmd_heads[idx]);
		if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "export") == 0)
			func_export(cmd_line_list->cmd_heads[idx]);
		idx++;
	}
}