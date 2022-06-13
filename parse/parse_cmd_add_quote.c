/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_add_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:22:14 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/13 21:39:30 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	join_quote(t_cmd_node **cmd_head, t_token_node **curr_token, char *line)
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

static int	new_quote(t_cmd_node **cmd_head, t_token_node **curr_token, char *line)
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

int	add_quote_cmd(t_cmd_node **cmd_head, t_token_node **curr_token, enum e_token_type type, char *line)
{
	char	temp_c;

	if ((*curr_token)->idx - 1 > 0)
		temp_c = line[(*curr_token)->idx - 1];
	else
		temp_c = '\0';
	if (temp_c != '\0' && !(temp_c == ' ' || temp_c >= 9 && temp_c <= 13))
		join_quote(cmd_head, curr_token, line);	// 앞쪽에 계속 join해줘야 합니다.
	else
		if (new_quote(cmd_head, curr_token, line) == FALSE)
			return (FALSE);	// 계속 새로 만들어진 노드에 넣어줘야 합니다.
	// 만약에 따옴표 뒤에 공백 없이 "다른 녀석"이 붙어온다면. (따옴표일 경우와 따옴표가 아닐 경우를 또 나눠줘야 한다.)
	// *curr_token = (*curr_token)->next;
	// temp_c = line[(*curr_token)->idx - 1];
	// while (temp_c != '\0' && !(temp_c == ' ' || temp_c >= 9 && temp_c <= 13))
	// 	join_quote(cmd_head, curr_token, line);// 앞쪽에 계속 join해줘야 합니다.
	return (TRUE);
}

