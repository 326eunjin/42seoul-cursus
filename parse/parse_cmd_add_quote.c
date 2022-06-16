/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_add_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:22:14 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/15 21:13:28 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	join_dquote(t_cmd_node **cmd_head, \
	t_token_node **curr, char *line)
{
	char		*new_str;
	t_cmd_node	*last_cmd;

	*curr = (*curr)->next;
	new_str = ft_strdup("");
	make_new_str(&new_str, curr, line);
	last_cmd = (*cmd_head);
	while (last_cmd->next != NULL)
		last_cmd = last_cmd->next;
	last_cmd->cmd = ft_strjoin(last_cmd->cmd, new_str);
}

static int	new_dquote(t_cmd_node **cmd_head, \
	t_token_node **curr, char *line)
{
	char		*new_str;
	t_cmd_node	*new_cmd;

	*curr = (*curr)->next;
	new_str = ft_strdup("");
	make_new_str(&new_str, curr, line);
	new_cmd = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_cmd == NULL)
	{
		free(new_str);
		return (FALSE);
	}
	ft_memset(new_cmd, 0, sizeof(t_cmd_node));
	new_cmd->cmd = new_str;
	new_cmd->type = COMMON;
	add_cmd(cmd_head, new_cmd);
	return (TRUE);
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
	if (type == QUOTE)
	{
		if (need_join(*curr_token, line, 1) == TRUE)
			join_quote(cmd_head, curr_token, line);
		else
			if (new_quote(cmd_head, curr_token, line) == FALSE)
				return (FALSE);
	}
	else
	{
		if (need_join(*curr_token, line, 1) == TRUE)
			join_dquote(cmd_head, curr_token, line);
		else
			if (new_dquote(cmd_head, curr_token, line) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}
