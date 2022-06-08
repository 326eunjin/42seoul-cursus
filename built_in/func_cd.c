/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 21:04:07 by ejang             #+#    #+#             */
/*   Updated: 2022/06/08 23:33:51 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void home_dir(char *str)//홈디렉토리로 이동
{//PWD 환경변수는 $HOME 으로 변경
	char *tmp1;
	if (chdir(str) <0)
	{
		printf("chdir erorr\n");
		g_state.exit_status = 1;
	}
	tmp1 = ft_strjoin("PWD=",str);
	func_export(tmp1);
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
	func_export(tmp);
	free(tmp);
	tmp = ft_strjoin("OLDPWD=", str2);
	func_export(tmp);
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
	ret = ft_strjoin("PWD=",str);
	func_export(ret);
	free(ret);
	ret = ft_strjoin("OLDPWD=",tmp);
	func_export(ret);
	free(ret);
}

void func_cd(int argc, char **argv)
{
	int ret = 0;
	char *str;
	str = get_value("HOME");
	if (argc == 1)//cd
		//go to home
		home_dir(str);
	else if(ft_strcmp(argv[1],"~") == 0)//아마 파싱 끝난 이후에 ft_strcmp(첫번째 arg,"0") == 0 이런식으로 바꿔야할듯!
		//cd ~
		//go to home
		home_dir(str);
	else if(ft_strcmp(argv[1],"-") == 0)
		//cd -
		//go to old pwd
		old_dir();
	else
		//cd 실행 
		change_dir(argv[1]);
}