/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:37:21 by ejang             #+#    #+#             */
/*   Updated: 2022/06/07 19:29:40 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	func_pwd(void)//현재 작업중인 절대경로 출력
// {
// 	char *current_dir = getcwd(NULL, 0);
// 	if (current_dir == NULL)//리턴값이 null이니까 free할 필요가 없음.
// 		printf("getcwd() cannot excute in fun_pwd\n");
// 	else
// 	{
// 	printf("%s\n",current_dir);
// 	free(current_dir);
// 	}
// }

void	func_pwd(t_cmd_line *cmd_line)//현재 작업중인 절대경로 출력
{
	char *current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)//리턴값이 null이니까 free할 필요가 없음.
		printf("getcwd() cannot excute in fun_pwd\n");
	else
	{
		printf("%s\n",current_dir);
		free(current_dir);
	}
}