/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:07 by ejang             #+#    #+#             */
/*   Updated: 2022/07/04 17:10:59 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**copy_envp(char **envp)
{
	int		i;
	int		cnt;
	char	**ret;
	char	*tmp;
	char	*pwd;

	i = 0;
	cnt = 0;
	while (envp[i])
	{
		cnt++;
		i++;
	}
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (envp[++i])
		ret[i] = ft_strdup(envp[i]);
	ret[cnt] = NULL;
	return (ret);
}
