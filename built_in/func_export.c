/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:07:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/21 11:01:30 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_in_envp(char *str)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(str, '=');
	while (g_state.envp[++i])
	{
		if (ft_strncmp(g_state.envp[i], split[0], ft_strlen(split[0])) == 0)
		{
			free_split(split);
			return (i);
		}
	}
	free_split(split);
	return (-1);
}

void	modify_envp(char *str, int loc)
{
	free(g_state.envp[loc]);
	g_state.envp[loc] = ft_strdup(str);
}

char	**new_export(char *str)
{
	int		i;
	int		cnt;
	char	**ret;

	i = -1;
	cnt = 0;
	while (g_state.envp[++i])
		cnt++;
	ret = (char **)malloc(sizeof(char *) * (cnt + 2));
	if (!ret)
		return (NULL);
	ret[cnt + 1] = NULL;
	i = -1;
	while (g_state.envp[++i])
		ret[i] = ft_strdup(g_state.envp[i]);
	ret[cnt] = ft_strdup(str);
	free(g_state.envp);
	return (ret);
}

int	has_equal_sign(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (TRUE);
	}
	return (FALSE);
}

int	is_right_form(char *str)
{
	int	i;

	i = -1;
	if (ft_isalpha(str[0]) == FALSE && str[0] != '_')
		return (FALSE);
	while (str[++i] != '=')
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
			return (FALSE);
	}
	return (TRUE);
}

void	func_export(t_cmd_node *head)
{
	int			idx;
	int			i;
	int			j;
	t_cmd_node	*curr_node;

	i = -1;
	j = -1;
	curr_node = head->next;
	while (curr_node != NULL)
	{
		if (is_right_form(curr_node->cmd) == FALSE)
			printf("bash: export: `%s': not a valid identifier\n", \
			curr_node->cmd);
		else if ((has_equal_sign(curr_node->cmd) == TRUE))
		{
			idx = is_in_envp(curr_node->cmd);
			if (idx != -1)
				modify_envp(curr_node->cmd, idx);
			else
				g_state.envp = new_export(curr_node->cmd);
		}
		curr_node = curr_node->next;
	}
}
