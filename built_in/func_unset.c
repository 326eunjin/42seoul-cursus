/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:58 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 04:18:35 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	envp_cnt(void)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (g_state.envp[++i])
		ret++;
	return (ret);
}

int	is_valid_env(char *str)
{
	int	i;

	i = -1;
	if (ft_isalpha(str[0]) == FALSE && str[0] != '_')
		return (FALSE);
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
			return (FALSE);
	}
	return (TRUE);
}

int	is_str_in_envp(char *str)
{
	int	i;

	i = -1;
	while (g_state.envp[++i])
	{
		if (ft_strncmp(str, g_state.envp[i], ft_strlen(str)) == 0)
			return (i);
	}
	return (FALSE);
}

static int	unset_error(char *cmd)
{
	ft_putstr_fd("bash : unset : ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
	return (TRUE);
}

void	func_unset(t_cmd_node *head)
{
	int			loc;
	int			flag;
	t_cmd_node	*curr_node;

	curr_node = head->next;
	flag = FALSE;
	while (curr_node != NULL)
	{
		if (is_valid_env(curr_node->cmd) == TRUE)
		{
			loc = is_str_in_envp(curr_node->cmd);
			if (loc != FALSE)
			{
				while (loc < envp_cnt() - 1)
				{
					free(g_state.envp[loc]);
					g_state.envp[loc] = ft_strdup(g_state.envp[loc + 1]);
					loc++;
				}
				g_state.envp[envp_cnt() - 1] = NULL;
			}
		}
		else if (is_right_form(curr_node->cmd) == FALSE)
			flag = unset_error(curr_node->cmd);
		curr_node = curr_node->next;
	}
	if (flag == TRUE)
		exit(1);
}
