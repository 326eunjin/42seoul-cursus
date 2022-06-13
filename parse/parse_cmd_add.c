/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:42 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/13 17:18:04 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*replace_dollar(char *str)
{
	char	**split;
	char	*ret;
	char	*name;
	int		idx;

	if (ft_strcmp(str, "$?") == 0)
		return (ft_itoa(g_state.exit_status));
	name = ft_substr(str, 1, ft_strlen(str));
	idx = is_in_envp(name);
	free(name);
	if (idx == -1)
		return (ft_strdup(""));
	split = ft_split(g_state.envp[idx], '=');
	if (split == 0)
		return(0);
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

int	add_dollar_cmd(t_cmd_node **cmd_head, t_token_node **curr_token)
{
	t_cmd_node *new_cmd;

	new_cmd = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_cmd == NULL)
		return (FALSE);
	ft_memset(new_cmd, 0, sizeof(t_cmd_node));
	new_cmd->cmd = replace_dollar((*curr_token)->token);
	if (new_cmd->cmd == NULL)
		return(FALSE);
	new_cmd->type = COMMON;
	add_cmd(cmd_head, new_cmd);
	return (TRUE);
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