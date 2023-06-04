/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:07:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/25 15:31:14 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		exit(1);
	ret[cnt + 1] = NULL;
	i = -1;
	while (g_state.envp[++i])
		ret[i] = ft_strdup(g_state.envp[i]);
	ret[cnt] = ft_strdup(str);
	ret[cnt + 1] = NULL;
	free_split(g_state.envp);
	return (ret);
}

static int	has_equal_sign(char *str)
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

	i = 0;
	if (ft_isalpha(str[0]) == FALSE && str[0] != '_')
		return (FALSE);
	if (has_equal_sign(str) == TRUE)
	{
		while (str[i] != '=')
		{
			if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
				return (FALSE);
			i++;
		}
		return (TRUE);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	func_export(t_cmd_node *head)
{
	int			flag;
	t_cmd_node	*curr_node;

	curr_node = head->next;
	flag = FALSE;
	export_wihtout_arg(head);
	while (curr_node != NULL)
	{
		if (is_right_form(curr_node->cmd) == FALSE)
		{
			flag = TRUE;
			ft_putstr_fd("bash : export : ", STDERR_FILENO);
			ft_putstr_fd(curr_node->cmd, STDERR_FILENO);
			ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
		}
		curr_node = curr_node->next;
	}
	if (flag == TRUE)
		exit(1);
}

void	func_export_single_cmd(t_cmd_node *head)
{
	int			idx;
	t_cmd_node	*curr_node;

	curr_node = head->next;
	export_wihtout_arg(head);
	while (curr_node != NULL)
	{
		if (is_right_form(curr_node->cmd) == FALSE)
		{
			ft_putstr_fd("bash : export : ", STDERR_FILENO);
			ft_putstr_fd(curr_node->cmd, STDERR_FILENO);
			ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
			g_state.exit_status = 1;
		}
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
