/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_add_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:22:14 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/14 14:00:14 by jeyoon           ###   ########seoul.kr  */
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
		if (c == '\'' || c == '"' || !(c == ' ' || c >= 9 && c <= 13))
			return (TRUE);
		return (FALSE);
	}
	else
	{
		if (c == '\'' || c == '"')
			return (TRUE);
		return (FALSE);
	}
}

static void	join_quote(t_cmd_node **cmd_head, \
	t_token_node **curr_token, char *line)
{
	int			start;
	int			end;
	char		*new_str;
	t_cmd_node	*last_cmd;

	*curr_token = (*curr_token)->next;
	start = (*curr_token)->idx;
	while ((*curr_token)->type != QUOTE)
		*curr_token = (*curr_token)->next;
	end = (*curr_token)->idx;
	new_str = ft_substr(line, start, end - start);
	last_cmd = (*cmd_head);
	while (last_cmd->next != NULL)
		last_cmd = last_cmd->next;
	last_cmd->cmd = ft_strjoin(last_cmd->cmd, new_str);
	free(new_str);
}

static int	new_quote(t_cmd_node **cmd_head, \
	t_token_node **curr_token, char *line)
{
	int			start;
	int			end;
	char		*new_str;
	t_cmd_node	*new_cmd;

	new_cmd = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_cmd == NULL)
		return (FALSE);
	ft_memset(new_cmd, 0, sizeof(t_cmd_node));
	*curr_token = (*curr_token)->next;
	start = (*curr_token)->idx;
	while ((*curr_token)->type != QUOTE)
		*curr_token = (*curr_token)->next;
	end = (*curr_token)->idx;
	new_str = ft_substr(line, start, end - start);
	new_cmd->cmd = new_str;
	new_cmd->type = COMMON;
	add_cmd(cmd_head, new_cmd);
	return (TRUE);
}

int	add_quote_cmd(t_cmd_node **cmd_head, t_token_node **curr_token, \
	enum e_token_type type, char *line)
{
	if (need_join(*curr_token, line, 1) == TRUE)
		join_quote(cmd_head, curr_token, line);
	else
		if (new_quote(cmd_head, curr_token, line) == FALSE)
			return (FALSE);
	return (TRUE);
}
