/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:07:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/06 21:19:24 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void free_split(char **tmp)
{
	int i = -1;
	int cnt = 0;
	while(tmp[++i])
		cnt++;
	i = -1;
	while (++i < cnt)
		free(tmp[i]);
	free(tmp);
}

char **new_export(char **envp, char *str)
{
	int i = -1;
	int cnt = 0;
	char **ret;
	while(envp[++i])
		cnt++;
	ret = (char **)malloc(sizeof(char *) * (cnt + 2));
	if (!ret)
		return (NULL);
	ret[cnt + 1] = NULL;
	i = -1;
	while (envp[++i])
		ret[i] = ft_strdup(envp[i]);
	ret[cnt] = ft_strdup(str);
	return (ret);
}

int has_equal_sign(char *str)
{
	int i = -1;
	while(str[++i])
	{
		if (str[i] == '=')
			return (TRUE);
	}
	return (FALSE);
}

int	is_right_form(char *str)
{
	int i = -1;

	if (ft_isalpha(str[0]) == FALSE && str[0] != '_')// 문자이거나 _
		return (FALSE);
	while(str[++i])
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_' && str[i] != '=')//숫자 문자 _ 가 아니면 
			return (FALSE);
	}
	return (TRUE);
}

void func_export(char ***envp, char *str)//func_export(&copy, "2h i hi hi=3") 이런식으로 호출
{
	char **tmp;
	char **ret;
	int i = -1;
	int cnt = 0;
	int j = -1;
	tmp = ft_split(str, ' ');
	cnt = get_count(str,' ');
	if (cnt == 1)
	{
		if (is_right_form(tmp[0]) == FALSE)
		{
			printf("bash: export: `%s': not a valid identifier\n",tmp[0]);
			free_split(tmp);
		}
		if (has_equal_sign(tmp[0]) == TRUE)
		{
			ret = new_export(*envp, tmp[0]);
			*envp = ret;
			free_split(tmp);
		}
		else
			free_split(tmp);
	}
	else//have space in str
	{
		while(++i < cnt)
		{
			if(is_right_form(tmp[i]) == FALSE)
				printf("bash: export: `%s': not a valid identifier\n",tmp[i]);
			else
			{
				ret = new_export(*envp, tmp[i]);
				*envp = ret;
			}
		}
		free_split(tmp);
	}
}
