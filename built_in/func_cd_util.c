/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:27:12 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 22:10:22 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	key_len(char *str)
{
	int	ret;
	int	i;

	ret = -1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (ret + 1);
		ret++;
	}
	return (ret);
}

static int	value_len(char *str)
{
	int	ret;
	int	i;

	ret = -1;
	i = -1;
	ret = ft_strlen(str) - key_len(str) - 1;
	return (ret);
}

char	*get_value(char *key)
{
	int		i;
	char	*ret;

	i = -1;
	ret = NULL;
	while (g_state.envp[++i])
	{
		if ((ft_strncmp(key, g_state.envp[i], ft_strlen(key)) == 0) \
		&& g_state.envp[i][ft_strlen(key)] == '=')
			ret = ft_substr(g_state.envp[i], key_len(g_state.envp[i]) + \
			1, value_len(g_state.envp[i]));
	}
	return (ret);
}

void	export_str(char *str)
{
	if (is_in_envp(str) != -1)
		modify_envp(str, is_in_envp(str));
	else
		g_state.envp = new_export(str);
}
