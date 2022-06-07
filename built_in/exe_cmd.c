/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/07 19:05:24 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    exe_cmd(t_cmd_line *cmd_line)
{
    if (ft_strcmp(cmd_line->head->cmd, "pwd") == 0)
        func_pwd(cmd_line);
}