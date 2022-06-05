/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:42:12 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/05 18:21:53 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// test
#include <stdio.h>

/*
    int parse_cmd(t_cmd_line *cmd_line) : main에서 호출되는 함수. 커맨드라인을 입력받고 cmd_line 구조체를 생성한다.
    static int cnt_node(t_cmd_line *cmd_line, char *line) : cmd_line.size를 결정하는 함수
*/

static int cnt_node(t_cmd_line *cmd_line, char *line)
{
    int idx;

    
}

int parse_cmd(t_cmd_line *cmd_line)
{
    char *line;

    line = readline("\033[0;36mMinishell>> \033[0m");
    add_history(line);
    printf("%s\n", line);
    cnt_node(cmd_line, line);
    free(line);
    return (TRUE);
}