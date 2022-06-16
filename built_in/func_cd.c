/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:04:07 by ejang             #+#    #+#             */
/*   Updated: 2022/06/16 16:27:41 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *get_pwd(void)
{
	char *current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)
	{
		printf("getcwd() cannot excute in fun_pwd\n");
		exit(1);
	}
	return (current_dir);
}

void home_dir(char *str)//홈디렉토리로 이동
{//PWD 환경변수는 $HOME 으로 변경
	char *tmp1;
	if (chdir(str) <0)
	{
		printf("chdir erorr\n");
		g_state.exit_status = 1;
	}
	tmp1 = ft_strdup("PWD=");
	tmp1 = ft_strjoin(tmp1,str);//"PWD=/home/ejang"
	export_str(tmp1);
	free(tmp1);
	free(str);
	tmp1 = 0;
	str = 0;
}

void old_dir()//OLDPWD 로 이동
{
	char *str1;
	char *str2;

	char *tmp;
	
	str1 = get_value("OLDPWD");
	str2 = get_value("PWD");
	if (chdir(str1) < 0)
	{
		printf("chdir error");
		g_state.exit_status = 1;
	}
	tmp = ft_strdup("PWD=");
	tmp = ft_strjoin(tmp,str1);
	free(str1);
	export_str(tmp);
	free(tmp);
	tmp = ft_strdup("OLDPWD=");
	tmp = ft_strjoin(tmp, str2);
	export_str(tmp);
	free(str2);
	free(tmp);
	str1 = 0;
	str2 = 0;
	tmp = 0;
}

void change_dir(char *str)//디렉토리 이동 
{

	char *tmp;
	char *ret;


	tmp = get_value("PWD");
	if (chdir(str) < 0)
	{
		printf("cd: no such file or directory: %s\n",str);
		g_state.exit_status = 1;
	}
	else
	{
		ret = ft_strdupp("PWD=");
		ret = ft_strjoin(ret,get_pwd());
		export_str(ret);
		free(ret);
		ret = ft_strdup("OLDPWD=");
		ret = ft_strjoin(ret,tmp);
		export_str(ret);
		free(ret);
		ret = 0;
	}
	free(tmp);
	tmp = 0;
}

//void func_cd(int argc, char **argv)
void	func_cd(t_cmd_node *head)
{
	t_cmd_node *curr_node;
	curr_node = head->next;
	
	int ret = 0;
	char *str;
	str = get_value("HOME");
	
	if (curr_node == NULL)//cd without no arguments
		//go to home
		home_dir(str);
	else if (ft_strcmp(curr_node->cmd,"~") == 0)
		//cd ~
		//go to home
		home_dir(str);
	else if(ft_strcmp(curr_node->cmd,"-") == 0)
		//cd -
		//go to old pwd
		old_dir();
	else
		//cd 실행 
		change_dir(curr_node->cmd);
}