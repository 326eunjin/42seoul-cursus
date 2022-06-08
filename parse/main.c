/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:33:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/08 23:26:51 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_cmd_line *cmd_line;
	//환경 변수 불러오기
	//if (is_in_envp("OLDPWD") == -1)
	//	add_old_pwd(); 만약에 OLDPWD 환경변수 없으면 추가하기
	while (1)
	{
		if (parse_cmd(&cmd_line) == FALSE)
		{
			//return_error(cmd_line);
			continue;
		}
		// 커맨드라인 유효성 검증 부분
		//*** 디버깅용 프린트 : 토큰들 한줄에 하나씩 프린트
		t_cmd_node *curr = cmd_line->head;
		for(int i = 0; i < cmd_line->len; i++)
		{
			printf("token #%d : %s (type : %d)\n", i + 1, curr->cmd, curr->type);
			curr = curr->next;
		}
		// *** 끝
		// 실행부분
		exe_cmd(cmd_line);
	}
	return (0);
}