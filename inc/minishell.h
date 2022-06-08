/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:20:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/08 14:23:13 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1

# define BUILTIN 1
# define OPTION 2
# define ARG 3
# define PIPE 4
# define REDIRIN 5
# define REDIROUT 6
# define HEREDOC 7
# define APPEND 8
# define DQUOTE 9
# define QUOTE 10

extern int	g_exit_status;

typedef struct s_cmd_node	t_cmd_node;
typedef struct s_cmd_line	t_cmd_line;
typedef struct s_state		t_state;

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

struct s_state//전역변수로 쓸 구조체
{
	char			**env;//환경변수
	int				exit_status;//종료 코드
	//추가 예정
}t_state

t_state				g_state;

/*
	*** parse ***
*/

int parse_cmd(t_cmd_line **cmd_line);
int  token_list(t_cmd_line **cmd_line, char *line);
int  token_cnt(t_cmd_line *cmd_line, char *line);
void token_analyze(t_cmd_line *cmd_line);


/*
	*** utils ***
*/
int	ft_strcmp(char *s1, char *s2);
char **copy_envp(char **envp);

/*
	*** execute commands ***
*/
void    exe_cmd(t_cmd_line *cmd_line);

/*
	built-in
*/
void	func_pwd(t_cmd_line *cmd_line);



#endif