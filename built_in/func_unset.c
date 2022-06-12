/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:58 by ejang             #+#    #+#             */
/*   Updated: 2022/06/12 23:20:22 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int envp_cnt(void)
{
	int i = -1;
	int ret = 0;
	while (g_state.envp[++i])
		ret++;
	return (ret);
}

int is_valid_env(char *str)
{
	int i = -1;
	if (ft_isalpha(str[0]) == FALSE && str[0] != '_') // 문자이거나 _
		return (FALSE);
	while (str[++i])
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_') //숫자 문자 _ 가 아니면
			return (FALSE);
	}
	return (TRUE);
}

int is_in_env(char *str) //환경변수 안에 해당 인자가 있는지
{
	int i = -1;
	while (g_state.envp[++i])
	{
		if (ft_strncmp(str, g_state.envp[i], ft_strlen(str)) == 0)
			return (i);
	}
	return (FALSE);
}

// void	ft_unset(char *str)
void func_unset(t_cmd_node *head)
{
	int loc = 0;
	int cnt = 0;
	t_cmd_node *curr_node;

	curr_node = head->next;
	cnt = envp_cnt();
	while (curr_node != NULL)
	{
		if (is_valid_env(curr_node->cmd) == TRUE)
		{
			loc = is_in_env(curr_node->cmd);
			if (loc != FALSE)
			{
				while (loc < cnt - 1)
				{
					free(g_state.envp[loc]);
					g_state.envp[loc] = ft_strdup(g_state.envp[loc + 1]);
					loc++;
				}
				g_state.envp[cnt - 1] = NULL;
			}
		}
		else if(is_right_form(curr_node->cmd) == FALSE)
			printf("error : unset '%s' : not a valid identifier\n", curr_node->cmd);
		curr_node = curr_node->next;
	}
}