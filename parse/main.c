/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:33:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/05 18:06:12 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(void)
{
    t_cmd_line *cmd_line;

    while (1)
    {
        if (parse_cmd(cmd_line) == FALSE)
        {
            //return_error(cmd_line);
            continue;
        }
        // 커맨드라인 유효성 검증 부분
        // 실행부분
    }
    return (0);
}