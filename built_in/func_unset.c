/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:58 by ejang             #+#    #+#             */
/*   Updated: 2022/06/25 15:56:16 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

static int	func_unset_2(t_cmd_node *head, int flag)
{
	t_cmd_node	*curr_node;
	int			loc;

	curr_node = head->next;
	while (curr_node != NULL)
	{
		if (is_right_form(curr_node->cmd) == FALSE)
			flag = unset_error(curr_node->cmd);
		curr_node = curr_node->next;
	}
	return (flag);
}

void	func_unset(t_cmd_node *head)
{
	int			flag;

	flag = func_unset_2(head, FALSE);
	if (flag == TRUE)
		exit(1);
}
