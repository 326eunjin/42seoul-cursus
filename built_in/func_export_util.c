/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:06:09 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 16:52:02 by ejang            ###   ########.fr       */
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

void	export_wihtout_arg(t_cmd_node *head)
{
	int	i;

	i = 0;
	if (head->next == NULL)
	{
		while (g_state.envp[i])
		{
			printf("declare -x %s\n", g_state.envp[i]);
			i++;
		}
	}
}
