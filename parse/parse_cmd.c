/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:54 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/14 13:48:29 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	int	cut_cmd_line(t_cmd_node **curr_cmd_head, t_token_node **curr_token, char *line)
{
	while (*curr_token != NULL && (*curr_token)->type != PIPE)
	{
		if ((*curr_token)->type == DQUOTE || (*curr_token)->type == QUOTE)
		{
			if (add_quote_cmd(curr_cmd_head, curr_token, (*curr_token)->type, line) == FALSE)
				return (FALSE);
		}
		else if ((*curr_token)->token[0] == '$')
		{
			if (add_dollar_cmd(curr_cmd_head, curr_token, line) == FALSE)
				return (FALSE);
		}
		else
			if (add_common_cmd(curr_cmd_head, curr_token, (*curr_token)->type, line) == FALSE)
				return (FALSE);
		*curr_token = (*curr_token)->next;
	}
	if ((*curr_token) != NULL)
		*curr_token = (*curr_token)->next;
	return (TRUE);
}

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

int	make_cmd_list(t_cmd_line_list **cmd_line_list, t_token_node *token_head, char *line)
{
	int				idx;
	t_token_node	*curr_token;
	if (cmd_check(*cmd_line_list, token_head) == FALSE)
		return (FALSE);
	(*cmd_line_list)->cmd_heads = (t_cmd_node **)malloc(sizeof(t_cmd_node *) * (*cmd_line_list)->size);
	if ((*cmd_line_list)->cmd_heads == NULL)
		return (FALSE);
	ft_memset((*cmd_line_list)->cmd_heads, 0, sizeof(t_cmd_node *) * (*cmd_line_list)->size);
	idx = 0;
	curr_token = token_head;
	while (idx < (*cmd_line_list)->size)
	{
		if (cut_cmd_line(&((*cmd_line_list)->cmd_heads[idx]), &curr_token, line) == FALSE)
			return (FALSE);
		idx++;
	}
	check_cmd_type((*cmd_line_list)->cmd_heads, (*cmd_line_list)->size);
	return (TRUE);
}
