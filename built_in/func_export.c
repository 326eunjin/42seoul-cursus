/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:07:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/08 13:26:13 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_split(char **tmp)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while(tmp[++i])
		cnt++;
	i = -1;
	while (++i < cnt)
		free(tmp[i]);
	free(tmp);
}

int	is_in_envp(char **envp, char *str)
{
	char **split;
	int i = -1;
	split = ft_split(str,'=');
	while (envp[++i])
	{
		if(ft_strncmp(envp[i],split[0],ft_strlen(split[0])) == 0)
		{
			free_split(split);
			return (i);
		}
	}
	free_split(split);
	return (-1);
}

void modify_envp(char **envp, char *str, int loc)
{
	free(envp[loc]);
	envp[loc] = ft_strdup(str);
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
	while(str[++i]!='=')
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')//숫자 문자 _ 가 아니면 
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
	tmp = ft_split(str, ' ');//공백 기준으로 자르기
	cnt = get_count(str,' ');//공백 기준으로 몇개 인지 확인
	if (cnt == 1)
	{
		if (is_right_form(tmp[0]) == FALSE)//ex. export 3=re;
		{
			printf("bash: export: `%s': not a valid identifier\n",tmp[0]);
			free_split(tmp);//free한거 해제
		}
		else if (has_equal_sign(tmp[0]) == TRUE)//export HI=hi
		{
			if (is_in_envp(*envp, tmp[0])!= -1)//만약에 key값이 envp에 있다면,
				modify_envp(*envp,tmp[0],is_in_envp(*envp, tmp[0]));//value를 변경 시켜줌.
			else//no key 
			{
				ret = new_export(*envp, tmp[0]);//export new variable
				*envp = ret;
				free_split(tmp);
			}
		}
		else//아무것도 안함. 
			free_split(tmp);
	}
	else//have space in str ex. export hi=HI ejang=EJ
	{
		while(++i < cnt)
		{
			if(is_right_form(tmp[i]) == FALSE)//ex. 3_e=hehe
				printf("bash: export: `%s': not a valid identifier\n",tmp[i]);
			else
			{
				if (is_in_envp(*envp, tmp[i])!= -1)//환경변수 안에 있다면  
					modify_envp(*envp, tmp[i], is_in_envp(*envp, tmp[i]));//추가하지말고 value 값을 변경해줌. 
				else
				{
					ret = new_export(*envp, tmp[i]);//환경변수 안에 없으므로 추가해줌. 
					*envp = ret;
				}
			}
		}
		free_split(tmp);
	}
}