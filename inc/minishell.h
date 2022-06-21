/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:20:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/21 23:42:11 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648
// 디버깅용 배열
extern char *to_types[];
extern char *cmd_types[];

enum	e_token_type
{
	TO_COMMON,
	TO_REDIRIN,
	TO_REDIROUT,
	TO_HEREDOC,
	TO_APPEND,
	PIPE,
	DQUOTE,
	QUOTE,
	DOLLAR
};

enum	e_cmd_type
{
	COMMON,
	REDIRIN,
	REDIROUT,
	HEREDOC,
	APPEND,
	REDIRARG,
	BUILTIN,
	OPTION
};

typedef struct s_token_node	t_token_node;
typedef struct s_cmd_node	t_cmd_node;
typedef struct s_cmd_line_list	t_cmd_line_list;
typedef struct s_state		t_state;

struct s_token_node	//	공백과 특수문자를 기준으로 잘린 부분 하나하나의 정보
{
	enum e_token_type	type;	//	토큰의 종류
	char				*token;	//	토큰 내용
	t_token_node		*prev;	//	연결리스트 연결부 (이전)
	t_token_node		*next;	//	연결리스트 연결부 (다음)
	int					idx;	//	입력된 line에서 이 토큰이 시작되는 인덱스
};

struct s_cmd_node	//	실행에서 사용되는 가장 작은 단위.
{
	enum e_cmd_type	type;	//	종류
	char			*cmd;	//	실제 내용
	t_cmd_node		*prev;	//	연결리스트 연결부 (이전)
	t_cmd_node		*next;	//	연결리스트 연결부 (다음)
};

struct s_cmd_line_list	//	t_cmd_node 연결리스트 배열의 정보
{
	int			size;	//	연결리스트 배열의 개수 (파이프로 잘린 영역의 개수)
	t_cmd_node	**cmd_heads;	//	연결리스트 배열. 하나의 인자가 하나의 파이프에서 실행되는 단위이다.
};

struct s_state//전역변수로 쓸 구조체
{
	char			**envp;//환경변수
	int				exit_status;//종료 코드
	//추가 예정
};

t_state		g_state;

/*
	*** parse ***
*/
int		parse_error(int option);
int		parse_cmd(t_cmd_line_list **cmd_line_list);
int		make_token_list(t_token_node **token_head, char *line);
int		make_cmd_list(t_cmd_line_list **cmd_line_list, t_token_node *token_head, char *line);
int		add_common_cmd(t_cmd_node **cmd_head, t_token_node **curr_token, enum e_token_type type, char *line);
int		add_dollar_cmd(t_cmd_node **cmd_head, t_token_node **curr_token, char *line);
int		need_join(t_token_node *curr_token, char *line, int option);
char	*replace_dollar(char *str, int idx, char *line);
void	make_new_str(char **new_str, t_token_node **curr, char *line);
int		check_cmd(t_cmd_node **cmd_heads, int size);
int		add_quote_cmd(t_cmd_node **cmd_head, t_token_node **curr_token, enum e_token_type type, char *line);
int		add_cmd(t_cmd_node **cmd_head, t_cmd_node *new_node);
void	dquote_dollar(char **curr_str, t_token_node **curr, char *line);
void	tolower_str(char *str);
char	*get_lower_str(char *str);
void	move_heredoc_curser(void);


/*
	*** utils ***
*/

void	set_signal();

/*
	*** utils ***
*/
int		ft_strcmp(char *s1, char *s2);
char	**copy_envp(char **envp);
void	free_split(char **tmp);
void	free_split_part(char **tmp, int idx);
void	free_array(char **tmp);

/*
	*** redirection ***
*/
char	*has_redir_in(t_cmd_node *node);
char	*without_redir(t_cmd_node *node);
t_cmd_node	*has_redir_out(t_cmd_node *node);
t_cmd_node	*remove_redir(t_cmd_node *head);
void	free_single_cmd_list(t_cmd_node *head);

/*
	*** execute commands ***
*/
void	exe_builtin(t_cmd_node	*node);
void	exe_cmd(t_cmd_line_list *cmd_line_list);
void	exe_single_cmd(t_cmd_node	*node,int ***fd, int size);
char	**string_array(t_cmd_node *node);
char	*is_valid_cmd(t_cmd_node *node);
/*
	built-in
*/
void	func_pwd(void);
void	func_env(void);
void	func_echo(t_cmd_node *head);
void	func_export(t_cmd_node *head);
void	func_unset(t_cmd_node *head);
void	func_cd(t_cmd_node *head);
void	func_exit(t_cmd_node *head);

int		is_right_form(char *str);
void	export_str(char *str);
int		is_in_envp(char *str);
void	modify_envp(char *str, int loc);
char	*get_value(char *key);
char	**new_export(char *str);
char	*get_pwd(void);
void	add_old_pwd(void);
void	func_exit_single_cmd(t_cmd_node *head);
#endif