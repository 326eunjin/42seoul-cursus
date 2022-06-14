/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:42 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/14 13:57:00 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*replace_dollar(char *str, int idx, char *line)
{
	char	**split;
	char	*ret;
	char	*name;
	char	envp_idx;

	if (idx < 1 || line[idx - 1] != '$')
		return (ft_strdup("$"));
	if (ft_strcmp(str, "?") == 0)
		return (ft_itoa(g_state.exit_status));
	envp_idx = is_in_envp(str);
	if (envp_idx == -1)
		return (ft_strdup(""));
	split = ft_split(g_state.envp[envp_idx], '=');
	if (split == 0)
		return (0);
	ret = ft_strdup(split[1]);
	free_split(split);
	return (ret);
}

void	add_cmd(t_cmd_node **cmd_head, t_cmd_node *new_node)
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

void	join_cmd(t_cmd_node **cmd_head, char *token)
{
	t_cmd_node	*last_cmd;

	last_cmd = (*cmd_head);
	while (last_cmd->next != NULL)
		last_cmd = last_cmd->next;
	last_cmd->cmd = ft_strjoin(last_cmd->cmd, token);
}

int	add_dollar_cmd(t_cmd_node **cmd_head, t_token_node **curr, char *line)
{
	t_cmd_node	*new_cmd;
	char		*str;

	if ((*curr)->next == NULL)
		str = ft_strdup("$");
	else
		str = replace_dollar((*curr)->next->token, (*curr)->next->idx, line);
	if (need_join(*curr, line, 2) == TRUE)
	{
		join_cmd(cmd_head, str);
		free(str);
		if ((*curr)->next != NULL)
			*curr = (*curr)->next;
		return (TRUE);
	}
	new_cmd = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_cmd == NULL)
		return (FALSE);
	ft_memset(new_cmd, 0, sizeof(t_cmd_node));
	new_cmd->cmd = str;
	new_cmd->type = COMMON;
	add_cmd(cmd_head, new_cmd);
	if ((*curr)->next != NULL)
		*curr = (*curr)->next;
	return (TRUE);
}

int	add_common_cmd(t_cmd_node **cmd_head, t_token_node **curr_token, \
		enum e_token_type type, char *line)
{
	t_cmd_node	*new_cmd;

	if (need_join(*curr_token, line, 3) == TRUE)
	{
		join_cmd(cmd_head, (*curr_token)->token);
		return (TRUE);
	}
	new_cmd = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_cmd == NULL)
		return (FALSE);
	ft_memset(new_cmd, 0, sizeof(t_cmd_node));
	new_cmd->cmd = (*curr_token)->token;
	new_cmd->type = (enum e_cmd_type)type;
	add_cmd(cmd_head, new_cmd);
	return (TRUE);
}
