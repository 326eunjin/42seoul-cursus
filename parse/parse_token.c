/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:32:02 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/07 15:45:04 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
    int token_list(t_cmd_line *cmd_line, char *line)    :   토큰을 세어주고 (token_cnt) , 리스트를 만드는 함수
    static int  make_token_list(t_cmd_line *cmd_line, char *line)    :   cmd_line.len만큼 노드를 할당하고 line에서 토큰을 잘라 연결리스트로 연결하는 함수
    static char *cut_token(char *line, int *start, int *end)    :   시작지점에서 공백, 혹은 따옴표가 등장하기 전까지의 토큰을 할당해서 반환하는 함수.
    static void add_token(t_cmd_line *cmd_line, t_cmd_node *new_node, int curr_size)    :   연결리스트 끝에 노드를 추가하는 함수.
*/

static char *cut_token(char *line, int *start, int *end)
{
    char *ret;

    *end = *start;
    // 1-1. 시작지점이 따옴표인 경우
    if (line[*start] == '"' || line[*start] == '\'')
    {
        (*end)++;
        // 1-2. 끝 부분이 시작지점의 따옴표가 아닌 경우동안 인덱스를 옮긴다. (짝이 안맞는 부분은 앞서서 처리해줬다.)
        while (line[*end] != line[*start])
            (*end)++;
        // 1-3. 시작부분부터 끝 부분까지의 문자열을 새로 잘라 만들어준다.
        ret = ft_substr(line, *start, (*end - *start + 1));
        // 1-4. end 인덱스가 부분 문자열에 포함되었으므로 인덱스를 증가시켜준다.
        *start = *end + 1;
    }
    // 2-1. 시작지점이 따옴표가 아닌 경우
    else
    {
        // 2-2. 공백이 등장하기 전까지 인덱스를 옮긴다.
        while (line[*end] != '\0' && !(line[*end] == ' ' || line[*end] >= 9 && line[*end] <= 13))
            (*end)++;
        // 2-3. 시작부분부터 끝 부분 앞까지의 문자열을 새로 잘라 만들어준다.
        ret = ft_substr(line, *start, (*end - *start));
        // 2-4. 인덱스를 업데이트시켜준다.
        *start = *end;
    }
    return (ret);
}

static void add_token(t_cmd_line *cmd_line, t_cmd_node *new_node, int curr_size)
{
    t_cmd_node *last_node;

    // 1. 첫 노드라면 head가 새로운 node를 가리키도록 한다.
    if (curr_size == 0)
        cmd_line->head = new_node;
    // 2. 그 외에는 연결리스트의 끝으로 가서 새 노드를 추가한다.
    else
    {
        last_node = cmd_line->head;
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
        new_node->prev = last_node;
    }   
}

static int make_token_list(t_cmd_line *cmd_line, char *line)
{
    int first_idx;
    int last_idx;
    int size;
    t_cmd_node *this_node;

    size = 0;
    first_idx = 0;
    while (size < cmd_line->len)
    {
        // 1. 새로운 노드 할당
        this_node = (t_cmd_node *)malloc(sizeof(t_cmd_node));
        if (this_node == NULL)
            return (FALSE);
        ft_memset(this_node, 0, sizeof(t_cmd_node));
        // 2. line에서 공백은 넘어가기
        while (line[first_idx] == ' ' || line[first_idx] >= 9 && line[first_idx] <= 13)
            first_idx++;
        // 3. 가장 처음 등장하는 공백이 아닌 부분에서부터 토큰을 자른다.
        this_node->cmd = cut_token(line, &first_idx, &last_idx);
        // 4. cut_token내 ft_substr 함수에서 메모리 할당 문제가 있었을 경우
        if (this_node->cmd == NULL)
        {
            free(this_node);
            return (FALSE);
        }
        // 4. 연결리스트 끝에 노드를 추가한다.
        add_token(cmd_line, this_node, size);
        size++;
    }
    return (TRUE);
}

int token_list(t_cmd_line *cmd_line, char *line)
{
    if (token_cnt(cmd_line, line) == FALSE)
    {
        // *** 디버깅용 프린트 : 따옴표 덜 닫혔을 경우 error 출력
        printf("error : 따옴표 짝이 맞지 않음\n");
        // *** 끝
        return (FALSE);
    }
    // *** 디버깅용 프린트 : 공백을 기준으로 한 토큰의 개수 출력
    printf("%d\n", cmd_line->len);
    // *** 끝
    if (make_token_list(cmd_line, line) == FALSE)
    {
        // *** 디버깅용 프린트 : 리스트 생성 실패 출력
        printf("error : malloc 실패\n");
        // *** 끝
        return (FALSE);
    }
    return (TRUE);
}