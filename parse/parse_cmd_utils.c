/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:42 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/12 21:06:01 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// add_quote_cmd
// add_dollar_cmd

static void	add_cmd(t_cmd_node **cmd_head, t_cmd_node *new_node)
{
	t_cmd_node	*last_node;

	if (*cmd_head == 0)
		*cmd_head = new_node;
	else
	{
		last_node = *cmd_head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

int	add_common_cmd(t_cmd_node **cmd_head, char *token, enum e_token_type type)
{
	t_cmd_node *new_cmd;

	new_cmd = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_cmd == NULL)
		return (FALSE);
	ft_memset(new_cmd, 0, sizeof(t_cmd_node));
	new_cmd->cmd = token;
	new_cmd->type = (enum e_cmd_type)type;
	add_cmd(cmd_head, new_cmd);
	return (TRUE);
}