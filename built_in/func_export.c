/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:07:54 by ejang             #+#    #+#             */
/*   Updated: 2022/06/13 15:58:36 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_split(char **tmp)//ft_split으로 할당한거 해제하기 
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
	tmp = NULL;
}

int	is_in_envp(char *str)//환경변수 안에 해당 문자열이 있는지?! 있으면 해당 인덱스 반환, 아니면 -1 리턴 
{
	char **split;
	int i = -1;
	split = ft_split(str,'=');
	while (g_state.envp[++i])
	{
		if(ft_strncmp(g_state.envp[i],split[0],ft_strlen(split[0])) == 0)
		{
			free_split(split);
			return (i);
		}
	}
	free_split(split);
	return (-1);
}

void modify_envp(char *str, int loc)//인덱스 값 문자열로 바꾸기(치환)
{
	free(g_state.envp[loc]);
	g_state.envp[loc] = ft_strdup(str);
}

char	**new_export(char *str)//새로운 문자열 추가
{
	//기존 할당한 사이즈 + 1 만큼 할당하고 기존꺼 다 복사, 마지막에 새로운 문자열도 추가, 그리고 기존꺼 할당 해제하고 새로운 문자열배열 넘겨줌 
	int i = -1;
	int cnt = 0;
	char **ret;
	while(g_state.envp[++i])
		cnt++;
	ret = (char **)malloc(sizeof(char *) * (cnt + 2));
	if (!ret)
		return (NULL);
	ret[cnt + 1] = NULL;
	i = -1;
	while (g_state.envp[++i])
		ret[i] = ft_strdup(g_state.envp[i]);
	ret[cnt] = ft_strdup(str);
	free(g_state.envp);
	return (ret);
}

int has_equal_sign(char *str)//= 등호가 있는지 없는지
{
	int i = -1;
	while(str[++i])
	{
		if (str[i] == '=')
			return (TRUE);
	}
	return (FALSE);
}

int	is_right_form(char *str)//key값만 확인 즉, = 까지 유효한지 확인
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

//void func_export(char *str)
void	func_export(t_cmd_node *head)
{
	//char **tmp;
	int i = -1;
	//int cnt = 0;
	int j = -1;
	// tmp = ft_split(str, ' ');//공백 기준으로 자르기
	// cnt = get_count(str,' ');//공백 기준으로 몇개 인지 확인
	t_cmd_node *curr_node;
	curr_node = head->next;
	while(curr_node != NULL)
	{
		if (is_right_form(curr_node->cmd) == FALSE)
			printf("bash: export: `%s': not a valid identifier\n",curr_node->cmd);
		else if ((has_equal_sign(curr_node->cmd) == TRUE))
		{
			if (is_in_envp(curr_node->cmd) != -1)
				modify_envp(curr_node->cmd, is_in_envp(curr_node->cmd));
			else// no key
				g_state.envp = new_export(curr_node->cmd);
		}
		curr_node = curr_node->next;
	}
}
