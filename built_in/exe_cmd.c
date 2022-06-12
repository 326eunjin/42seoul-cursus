/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/12 23:19:31 by ejang            ###   ########.fr       */
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
		if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "unset") == 0)
			func_unset(cmd_line_list->cmd_heads[idx]);
		idx++;
	}
}