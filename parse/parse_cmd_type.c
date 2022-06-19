/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:21:28 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/19 19:52:12 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_echo_option(t_cmd_node *node)
{
	int	idx;

	if (node != NULL && node->cmd[0] == '-')
	{
		idx = 1;
		while (node->cmd[idx] != '\0')
		{
			if (node->cmd[idx] != 'n')
				return (FALSE);
			idx++;
		}
		return (TRUE);
	}
	return (FALSE);
}

static int	is_builtin(t_cmd_node **curr)
{
	int		ret;
	char	*temp;

	temp = get_lower_str((*curr)->cmd);
	ret = FALSE;
	if (ft_strcmp(temp, "echo") == 0)
	{
		(*curr)->type = BUILTIN;
		if (is_echo_option((*curr)->next) == TRUE)
		{
			*curr = (*curr)->next;
			(*curr)->type = OPTION;
		}
		ret = TRUE;
	}
	else if (!ft_strcmp(temp, "cd") || !ft_strcmp(temp, "pwd") || \
		!ft_strcmp(temp, "export") || !ft_strcmp(temp, "unset") || \
		!ft_strcmp(temp, "env") || !ft_strcmp(temp, "exit"))
	{
		(*curr)->type = BUILTIN;
		ret = TRUE;
	}
	free(temp);
	return (ret);
}

static int	check_redir(t_cmd_node **curr_cmd)
{
	if ((*curr_cmd)->type == REDIRIN || \
		(*curr_cmd)->type == REDIROUT || \
		(*curr_cmd)->type == HEREDOC || \
		(*curr_cmd)->type == APPEND)
	{
		if ((*curr_cmd)->next == NULL)
			return (parse_error(3));
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
	char		*temp;

	idx = 0;
	while (idx < size)
	{
		cmd_flag = FALSE;
		curr = cmd_heads[idx];
		while (curr != NULL)
		{
			if (check_redir(&curr) == FALSE)
				return (FALSE);
			if (cmd_flag == FALSE && curr->type == COMMON && \
				(is_builtin(&curr) == TRUE))
			{
				tolower_str(curr->cmd);
				cmd_flag = TRUE;
			}
			curr = curr->next;
		}
		idx++;
	}
	return (TRUE);
}
