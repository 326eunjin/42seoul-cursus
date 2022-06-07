/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:46:59 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/07 21:08:24 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	static int  token_cnt(t_cmd_line *cmd_line, char *line)	: cmd_line.len을 결정하는 함수
	static int  token_quote(int *idx, char *line)	: 따옴표가 있는 토큰의 인덱스 옮겨주기 (따옴표가 짝맞춰 닫히는지도 확인한다.)
*/

static int  token_quote(int *idx, char *line)
{
	char	quote;

	quote = line[*idx];
	(*idx)++;
	 // 1. 동일한 따옴표가 등장하기 전까지 계속 인덱스를 옮김
	while (line[*idx] != '\0' && line[*idx] != quote)
		(*idx)++;
	// 2. 만약에 동일한 따옴표로 닫기기 전에 라인이 끝난다면 에러를 출력한다.
	if (line[*idx] == '\0')
		return (FALSE);
	(*idx)++;
	return (TRUE);
}

int  token_cnt(t_cmd_line *cmd_line, char *line)
{
	int idx;

	idx = 0;
	cmd_line->len = 0;
	while (line[idx] != '\0')
	{
		// 1. 공백부분 무조건 건너뛰기
		while (line[idx] != '\0' && (line[idx] == ' ' || line[idx] >= 9 && line[idx] <= 13))
		idx++;
		// 2. 공백으로만 채워진 문자열이었을 경우 함수 종료
		if (line[idx] == '\0')
			return (FALSE);
		(cmd_line->len)++;
		// 3-1. 따옴표인 경우 닫힐때까지 하나의 t_cmd_node로 취급한다.
		if (line[idx] == '"' || line[idx] == '\'')
		{
			if (token_quote(&idx, line) == FALSE)
				return (FALSE);
			continue;
		}
		// 3-2. 따옴표 외의 경우 다음 공백이 나오기 전까지 하나의 t_cmd_node로 취급한다.
		while (line[idx] != '\0' && !(line[idx] == ' ' || line[idx] >= 9 && line[idx] <= 13))
			idx++;
	}
	if (cmd_line->len == 0)
		return (FALSE);
	return (TRUE);
}