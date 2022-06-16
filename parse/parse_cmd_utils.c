/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:22:53 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/15 21:14:21 by jeyoon           ###   ########seoul.kr  */
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

void	make_new_str(char **new_str, t_token_node **curr, char *line)
{
	int			start;
	int			end;

	start = (*curr)->idx;
	while ((*curr)->type != DQUOTE)
	{
		if ((*curr)->type == DOLLAR)
			dquote_dollar(new_str, curr, line);
		else
		{
			end = (*curr)->idx + ft_strlen((*curr)->token);
			*new_str = ft_strjoin(*new_str, \
				ft_substr(line, start, end - start));
			start = (*curr)->next->idx;
		}
		*curr = (*curr)->next;
	}
}

void	dquote_dollar(char **curr_str, t_token_node **curr, char *line)
{
	char	*str;

	if ((*curr)->next == NULL)
		str = ft_strdup("$");
	else
		str = replace_dollar((*curr)->next->token, (*curr)->next->idx, line);
	*curr_str = ft_strjoin(*curr_str, str);
	if ((*curr)->next != NULL)
		*curr = (*curr)->next;
}
