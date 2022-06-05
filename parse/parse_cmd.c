/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:12 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/06 02:57:33 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// test
#include <stdio.h>

/*
    int parse_cmd(t_cmd_line *cmd_line) : main에서 호출되는 함수. 커맨드라인을 입력받고 cmd_line 구조체를 생성한다.
    static int token_cnt(t_cmd_line *cmd_line, char *line) : cmd_line.size를 결정하는 함수
    static int  token_quote(int *idx, char *line) : 따옴표가 있는 토큰의 인덱스 옮겨주기 (따옴표가 짝맞춰 닫히는지도 확인한다.)
*/

static int  token_quote(int *idx, char *line)
{
    char    quote;

    quote = line[*idx];
    (*idx)++;
    // 1. 동일한 따옴표가 등장하기 전까지 계속 인덱스를 옮김
    while (line[*idx] != '\0' && line[*idx] != quote)
        (*idx)++;
    // 2. 만약에 동일한 따옴표로 닫기기 전에 라인이 끝난다면 에러를 출력한다.
    // (멀티라인 입력을 지원해야 하는지 여부는 확인이 필요합니다.)
    if (line[*idx] == '\0')
        return (FALSE);
    (*idx)++;
    return (TRUE);
}

static int  token_cnt(t_cmd_line *cmd_line, char *line)
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
            return (TRUE);
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
    return (TRUE);
}

int parse_cmd(t_cmd_line *cmd_line)
{
    char *line;

    cmd_line = (t_cmd_line *)malloc(sizeof(t_cmd_line));
    if (cmd_line == NULL)
        return (FALSE);
    line = readline("\033[0;36mMinishell>> \033[0m");
    add_history(line);
    // *** 디버깅용 프린트 : 입력받은 한 줄 출력
    printf("%s\n", line);
    // *** 끝
    if (token_cnt(cmd_line, line) == FALSE)
    {
        // *** 디버깅용 프린트 : 따옴표 덜 닫혔을 경우 error 출력
        printf("error\n");
        // *** 끝
        return (FALSE);
    }
    // *** 디버깅용 프린트 : 공백을 기준으로 한 토큰의 개수 출력
    printf("%d\n", cmd_line->len);
    // *** 끝
    free(line);
    return (TRUE);
}