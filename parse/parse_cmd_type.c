/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:21:28 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/15 20:48:21 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_echo_option(char *str)
{
	int	idx;

	idx = 1;
	while (str[idx] != '\0')
	{
		if (str[idx] != 'n')
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static int	is_builtin(t_cmd_node **curr_cmd)
{
	if (ft_strcmp((*curr_cmd)->cmd, "echo") == 0)
	{
		(*curr_cmd)->type = BUILTIN;
		if ((*curr_cmd)->next != NULL && (*curr_cmd)->next->cmd[0] == '-')
		{
			if (is_echo_option((*curr_cmd)->next->cmd) == TRUE)
			{
				*curr_cmd = (*curr_cmd)->next;
				(*curr_cmd)->type = OPTION;
			}
		}
		return (TRUE);
	}
	else if (!ft_strcmp((*curr_cmd)->cmd, "cd") || \
		!ft_strcmp((*curr_cmd)->cmd, "pwd") || \
		!ft_strcmp((*curr_cmd)->cmd, "export") || \
		!ft_strcmp((*curr_cmd)->cmd, "unset") || \
		!ft_strcmp((*curr_cmd)->cmd, "env") || \
		!ft_strcmp((*curr_cmd)->cmd, "exit"))
	{
		(*curr_cmd)->type = BUILTIN;
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	check_redir(t_cmd_node **curr_cmd)
{
	if ((*curr_cmd)->type == REDIRIN || \
		(*curr_cmd)->type == REDIROUT || \
		(*curr_cmd)->type == HEREDOC || \
		(*curr_cmd)->type == APPEND)
	{
		if ((*curr_cmd)->next == NULL)
			return (FALSE);
		else
		{
			*curr_cmd = (*curr_cmd)->next;
			(*curr_cmd)->type = REDIRARG;
		}
	}
	return (TRUE);
}

int	check_cmd(t_cmd_node **cmd_heads, int size)
{
	int			idx;
	int			cmd_flag;
	t_cmd_node	*curr;

	idx = 0;
	cmd_flag = FALSE;
	while (idx < size)
	{
		curr = cmd_heads[idx];
		while (curr != NULL)
		{
			if (check_redir(&curr) == FALSE)
				return (FALSE);
			if (cmd_flag == FALSE && curr->type == COMMON && \
				(is_builtin(&curr)) == TRUE)
				cmd_flag = TRUE;
			curr = curr->next;
		}
		idx++;
	}
	return (TRUE);
}
