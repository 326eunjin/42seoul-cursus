/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:33:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/09 17:34:47 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// 디버깅용
char *to_types[] = {"TO_COMMON", "TO_REDIRIN", "TO_REDIROUT", "TO_HEREDOC", "TO_APPEND", "PIPE", "DQUOTE", "QUOTE"};
char *cmd_types[] = {"COMMON", "REDIRIN", "REDIROUT", "HEREDOC", "APPEND", "BUILTIN", "OPTION"};

int main(int argc, char **argv, char **envp)
{
	t_cmd_line_list *cmd_line_list;
	//환경 변수 불러오기
	//if (is_in_envp("OLDPWD") == -1)
	//	add_old_pwd(); 만약에 OLDPWD 환경변수 없으면 추가하기
	while (1)
	{
		if (parse_cmd(&cmd_line_list) == FALSE)
		{
			//return_error(cmd_line);
			continue;
		}
		// 커맨드라인 유효성 검증 부분
		// 실행부분
		//exe_cmd(cmd_line);
	}
	return (0);
}