/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:27:12 by ejang             #+#    #+#             */
/*   Updated: 2022/06/08 23:31:22 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void add_old_pwd()//OLDPWD 환경 변수 추가하기
{
	char *pwd;
	char *tmp;
	tmp = get_pwd();
	pwd = ft_strjoin("OLDPWD=",tmp);
	free(tmp);
	func_export(pwd);
	free(pwd);
}

int key_len(char *str)//key값의 길이 리턴 
{
	int ret = -1;
	int i = -1;
	while(str[++i])
	{
		if(str[i] == '=')
			return (ret + 1);
		ret++;
	}
	return (ret);//없으면 -1 리턴 
	//만약에 = 이런식이면 0 리턴 
}

int value_len(char *str)//value 길이 리턴
{
	int ret = -1;
	int i = -1;
	ret = ft_strlen(str) - key_len(str) - 1;
	return (ret);//만약에 int= 이면 0 리턴
}

char *get_value(char *key)//value값 리턴해주는 함수 
{
	int i = -1;
	char *ret = NULL;
	while(g_state.envp[++i])
	{
		if((ft_strncmp(key,g_state.envp[i],ft_strlen(key)) == 0) && g_state.envp[i][ft_strlen(key)] =='=')
			ret = ft_substr(g_state.envp[i],key_len(g_state.envp[i]) + 1, value_len(g_state.envp[i]));
	}
	return (ret);
}//ret은 호출함수에서 나중에 free해줘야함. 