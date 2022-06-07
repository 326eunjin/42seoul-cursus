/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:12 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/07 18:46:47 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// test
#include <stdio.h>

/*
	int parse_cmd(t_cmd_line *cmd_line) : main에서 호출되는 함수. 커맨드라인을 입력받고 cmd_line 구조체를 생성한다.
*/

int	parse_cmd(t_cmd_line **cmd_line)
{
	char	*line;

	// 1. cmd_line 구조체 동적할당
	*cmd_line = (t_cmd_line *)malloc(sizeof(t_cmd_line));
	if (*cmd_line == NULL)
		return (FALSE);
	// 2. "한 줄" 읽어들이기
	line = readline("\033[0;36mMinishell>> \033[0m");
	// 3. EOF가 입력되었을 경우 (ctrl - d) 처리
	if (line == NULL)
	{
		// *** 디버깅용 프린트 : ctrl - d 입력시 예외처리
		printf("ctrl - d\n");
		// *** 끝
		return (TRUE);
	}
	// 3. history에 추가
	add_history(line);
	// *** 디버깅용 프린트 : 입력받은 한 줄 출력
	printf("%s\n", line);
	// *** 끝
	// 4. 토큰화만 해 주기 (단순히 잘라서 연결리스트 생성.)
	if (token_list(cmd_line, line) == FALSE)
	{
		// *** 디버깅용 프린트 : 토큰 리스트 생성에서 error
		printf("error : in 토큰 리스트 생성\n");
		// *** 끝
		return (FALSE);
	}
	// *** 끝
	token_analyze(*cmd_line);
	free(line);
	return (TRUE);
}
