/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:54 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/09 21:14:59 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	cmd_check(t_cmd_line_list *cmd_line_list, t_token_node *token_head)
{
	t_token_node		*this_node;
	enum e_token_type	type;

	this_node = token_head;
	cmd_line_list->size = 1;
	while (this_node != NULL)
	{
		if (this_node->type == PIPE)
			cmd_line_list->size++;
		else if (this_node->type == DQUOTE || this_node->type == QUOTE)
		{
			type = this_node->type;
			this_node = this_node->next;
			while (this_node != NULL)
			{
				if (this_node->type == type)
					break;
				this_node = this_node->next;
			}
			if (this_node == NULL)
				return (FALSE);
		}
		this_node = this_node->next;
	}
	return (TRUE);
}

int	make_cmd_list(t_cmd_line_list *cmd_line_list, t_token_node *token_head, char *line)
{
	if (cmd_check(cmd_line_list, token_head) == FALSE)
		return (FALSE);
	cmd_line_list->cmd_heads = (t_cmd_node **)malloc(sizeof(t_cmd_node *) * cmd_line_list->size);
	if (cmd_line_list->cmd_heads == NULL)
		return (FALSE);
	printf("cmd_heads_size = %d\n", cmd_line_list->size);
	return (TRUE);
}
