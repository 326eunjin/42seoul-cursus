/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/13 21:38:57 by ejang            ###   ########.fr       */
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

	// while (idx < cmd_line_list->size)
	// {
	// 	if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "pwd") == 0)
	// 		func_pwd();
	// 	if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "env") == 0)
	// 		func_env();
	// 	if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "echo") == 0)
	// 		func_echo(cmd_line_list->cmd_heads[idx]);
	// 	if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "export") == 0)
	// 		func_export(cmd_line_list->cmd_heads[idx]);
	// 	if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "unset") == 0)
	// 		func_unset(cmd_line_list->cmd_heads[idx]);
	// 	if (ft_strcmp(cmd_line_list->cmd_heads[idx]->cmd, "cd") == 0)
	// 		func_cd(cmd_line_list->cmd_heads[idx]);
	// 	idx++;
	// }
}

// void	exe_cmd(t_cmd_line_list *cmd_line_list)
// {
// 	int idx = 0;
// 	while(idx < cmd_line_list->size)
// 	{
// 		if ()
// 		idx++;
// 	}
// }