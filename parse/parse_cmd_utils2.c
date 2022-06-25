/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:58:59 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/26 00:03:20 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	need_join(t_token_node *curr_token, char *line, int option)
{
	char	c;

	if (curr_token->idx - 1 > 0)
		c = line[curr_token->idx - 1];
	else
		c = '\0';
	if (option == 1)
	{
		if (c != '\0' && !(c == ' ' || c >= 9 && c <= 13))
			return (TRUE);
		return (FALSE);
	}
	else if (option == 2)
	{
		if (c != '\0' && (c == '\'' || c == '"' || \
			!(c == ' ' || c >= 9 && c <= 13)))
			return (TRUE);
		return (FALSE);
	}
	else
	{
		if (c != '\0' && (c == '\'' || c == '"'))
			return (TRUE);
		return (FALSE);
	}
}

enum e_token_type	get_token_type(char *line, int idx)
{
	if (line[idx] == '"')
		return (DQUOTE);
	else if (line[idx] == '\'')
		return (QUOTE);
	else if (line[idx] == '|')
		return (PIPE);
	else if (line[idx] == '$')
		return (DOLLAR);
	else if (line[idx] == '<')
	{
		if (line[idx + 1] != '\0' && line[idx + 1] == '<')
			return (TO_HEREDOC);
		return (TO_REDIRIN);
	}
	else if (line[idx] == '>')
	{
		if (line[idx + 1] != '\0' && line[idx + 1] == '>')
			return (TO_APPEND);
		return (TO_REDIROUT);
	}
	return (TO_COMMON);
}

int	add_token(t_token_node **token_head, t_token_node **new_node, \
	enum e_token_type type, int idx)
{
	t_token_node	*last_node;

	(*new_node)->type = type;
	(*new_node)->idx = idx;
	if (*token_head == NULL)
		*token_head = *new_node;
	else
	{
		last_node = *token_head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = *new_node;
		(*new_node)->prev = last_node;
	}
	return (TRUE);
}
