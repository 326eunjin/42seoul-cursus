/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:04:58 by ejang             #+#    #+#             */
/*   Updated: 2022/06/06 21:22:25 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int envp_cnt(char **envp)
{
	int i = -1;
	int ret = 0;
	while(envp[++i])
		ret++;
	return (ret);
}

int is_valid_env(char *str)
{
	int i = 0;
	if (ft_isalpha(str[0]) == FALSE && str[0] != '_')// 문자이거나 _
		return (FALSE);
	while(str[++i])
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')//숫자 문자 _ 가 아니면 
			return (FALSE);
	}
	return (TRUE);
}

int is_in_env(char **envp, char *str)//환경변수 안에 해당 인자가 있는지 
{
	int i = -1;
	while(envp[++i])
	{
		if (ft_strncmp(str, envp[i], ft_strlen(str)) == 0)
			return (i);
	}
	return (FALSE);
}

void	ft_unset(char **envp, char *str)
{
	int loc = 0;
	int cnt = 0;
	
	cnt = envp_cnt(envp);
	if (is_valid_env(str) == TRUE)
	{
		loc = is_in_env(envp, str);
		if (loc != FALSE)
		{
			while(loc < cnt - 1)
			{
				free(envp[loc]);
				envp[loc] = ft_strdup(envp[loc + 1]);
				loc++;
			}
			envp[cnt - 1] = NULL;
		}
	}
	else
		printf("error : unset '%s' : not a valid identifier\n",str);
}