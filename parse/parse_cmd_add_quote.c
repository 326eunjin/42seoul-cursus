/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_add_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:22:14 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/25 22:50:02 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	join_dquote(t_cmd_node **cmd_head, \
	t_token_node **curr, char *line)
{
	char		*new_str;
	t_cmd_node	*last_cmd;

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

	new_str = ft_strdup((*curr_token)->token);
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
	new_str = ft_strdup((*curr_token)->token);
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
		{
			printf("11111\n");
			join_quote(cmd_head, curr_token, line);
		}
		else
		{
			printf("22222\n");
			if (new_quote(cmd_head, curr_token, line) == FALSE)
				return (FALSE);
		}
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
