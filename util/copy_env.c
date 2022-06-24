/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:07 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 22:11:29 by ejang            ###   ########.fr       */
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

	i = -1;
	cnt = 0;
	while (envp[++i])
		cnt++;
	ret = (char **)malloc(sizeof(char *) * (cnt + 2));
	if (!ret)
		return (NULL);
	i = -1;
	while (envp[++i])
		ret[i] = ft_strdup(envp[i]);
	pwd = ft_strjoin(ft_strdup("OLDPWD="), get_pwd());
	ret[cnt] = pwd;
	ret[cnt + 1] = NULL;
	return (ret);
}
