/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:22:53 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/25 16:46:47 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	get_end_index(t_token_node **curr)
{
	int	end;

	if ((*curr)->next == NULL)
		end = (*curr)->idx + ft_strlen((*curr)->token);
	else
		end = (*curr)->next->idx;
	return (end);
}

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

char	*replace_dollar(char *str, int idx, char *line)
{
	char	**split;
	char	*ret;
	char	*name;
	char	envp_idx;

	if (idx < 1 || line[idx - 1] != '$')
		return (ft_strdup("$"));
	if (ft_strcmp(str, "\"") == 0)
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

void	make_new_str(char **new_str, t_token_node **curr, char *line)
{
	int			start;
	int			end;

	while (*curr != NULL)
	{
		if ((*curr)->type == DOLLAR)
			dquote_dollar(new_str, curr, line);
		else
		{
			if ((*curr)->prev != NULL && (*curr)->type != DQUOTE)
			start = (*curr)->prev->idx + ft_strlen((*curr)->prev->token);
			else
				start = (*curr)->idx + 1;
			while ((*curr)->next != NULL && !((*curr)->next->type == DOLLAR \
				|| (*curr)->next->type == DQUOTE))
				*curr = (*curr)->next;
			end = get_end_index(curr);
			*new_str = ft_strjoin(*new_str, \
				ft_substr(line, start, end - start));
		}
		*curr = (*curr)->next;
		if ((*curr)->type == DQUOTE)
			return ;
	}
}

void	dquote_dollar(char **curr_str, t_token_node **curr, char *line)
{
	char	*str;
	int		start;

	if ((*curr)->next == NULL)
		str = ft_strdup(" ");
	else
		str = replace_dollar((*curr)->next->token, (*curr)->next->idx, line);
	*curr_str = ft_strjoin(*curr_str, str);
	if ((*curr)->next->type == DQUOTE)
		return ;
	if ((*curr)->next != NULL)
		*curr = (*curr)->next;
	if ((*curr)->next->type == DQUOTE)
	{
		start = (*curr)->idx + ft_strlen((*curr)->token);
		*curr_str = ft_strjoin(*curr_str, \
		ft_substr(line, start, (*curr)->next->idx - start));
	}
}
