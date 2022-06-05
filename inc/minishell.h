/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:20:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/05 16:27:11 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CMD 1
# define OPTION 2
# define ARG 3
# define PIPE 4
# define REDIRIN 5
# define REDIROUT 6
# define HEREDOC 7
# define APPEND 8

typedef struct s_cmd_node	t_cmd_node;
typedef struct s_cmd_line	t_cmd_line;

struct s_cmd_node // 공백을 기준으로 잘린 부분 하나하나의 정보
{
	int			type; // cmd의 종류
	char		*cmd; // 실제 입력된 커맨드 
	t_cmd_node	*prev; // 연결리스트 연결부 (이전)
	t_cmd_node	*next; // 연결리스트 연결부 (다음)
};

struct s_cmd_line // 한 줄에 입력된 명령어 라인에 대한 정보
{
	int			len; // 명령어 라인의 총 길이
	t_cmd_node	*head; // 연결리스트 시작부분
};

#endif