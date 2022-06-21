/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:07 by ejang             #+#    #+#             */
/*   Updated: 2022/06/21 11:08:23 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**copy_envp(char **envp)
{
	int		i;
	int		cnt;
	char	**ret;

	i = -1;
	cnt = 0;
	while (envp[++i])
		cnt++;
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (envp[++i])
		ret[i] = ft_strdup(envp[i]);
	ret[cnt] = NULL;
	return (ret);
}
