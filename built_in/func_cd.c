/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:04:07 by ejang             #+#    #+#             */
/*   Updated: 2022/06/15 13:16:15 by ejang            ###   ########.fr       */
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
	tmp1 = ft_strjoin("PWD=",str);//"PWD=/home/ejang"
	export_str(tmp1);
	free(tmp1);
	free(str);
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
	tmp = ft_strjoin("PWD=",str1);
	free(str1);
	export_str(tmp);
	free(tmp);
	tmp = ft_strjoin("OLDPWD=", str2);
	export_str(tmp);
	free(str2);
	free(tmp);
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
		ret = ft_strjoin("PWD=",get_pwd());
		export_str(ret);
		free(ret);
		ret = ft_strjoin("OLDPWD=",tmp);
		export_str(ret);
		free(ret);
	}
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