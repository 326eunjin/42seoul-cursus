/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:20:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/23 17:07:11 by ejang            ###   ########.fr       */
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

extern char	*to_types[];
extern char	*cmd_types[];

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

typedef struct s_token_node		t_token_node;
typedef struct s_cmd_node		t_cmd_node;
typedef struct s_cmd_line_list	t_cmd_line_list;
typedef struct s_state			t_state;
t_state							g_state;

struct s_token_node
{
	enum e_token_type	type;
	char				*token;
	t_token_node		*prev;
	t_token_node		*next;
	int					idx;
};

struct s_cmd_node
{
	enum e_cmd_type	type;
	char			*cmd;
	t_cmd_node		*prev;
	t_cmd_node		*next;
};

struct s_cmd_line_list
{
	int			size;
	t_cmd_node	**cmd_heads;
};

struct s_state
{
	char			**envp;
	int				exit_status;
};

/*
	*** parse ***
*/
int			parse_error(int option);
int			parse_cmd(t_cmd_line_list **cmd_line_list);
int			make_token_list(t_token_node **token_head, char *line);
int			make_cmd_list(t_cmd_line_list **cmd_line_list, \
	t_token_node *token_head, char *line);
int			add_common_cmd(t_cmd_node **cmd_head, \
	t_token_node **curr_token, enum e_token_type type, char *line);
int			add_dollar_cmd(t_cmd_node **cmd_head, \
	t_token_node **curr_token, char *line);
int			need_join(t_token_node *curr_token, char *line, int option);
char		*replace_dollar(char *str, int idx, char *line);
void		make_new_str(char **new_str, t_token_node **curr, char *line);
int			check_cmd(t_cmd_node **cmd_heads, int size);
int			add_quote_cmd(t_cmd_node **cmd_head, \
	t_token_node **curr_token, enum e_token_type type, char *line);
int			add_cmd(t_cmd_node **cmd_head, t_cmd_node *new_node);
void		dquote_dollar(char **curr_str, t_token_node **curr, char *line);
void		tolower_str(char *str);
char		*get_lower_str(char *str);
void		move_heredoc_curser(int fd);

/*
	*** utils ***
*/
char		**copy_envp(char **envp);
void		free_split(char **tmp);
void		free_split_part(char **tmp, int idx);
void		free_array(char **tmp);
int			ft_strcmp(char *s1, char *s2);
void		set_main_signal(void);
void		set_heredoc_signal(void);
void		set_exec_signal(void);
void		sig_main_handler(int sig);
void		sigint_exec_handler(int sig);
void		sigquit_exec_handler(int sig);
void		sig_heredoc_handler(int sig);

/*
	*** redirection ***
*/
int			mini_heredoc(t_cmd_node **curr_cmd);
void		redir_in(t_cmd_node *node);
void		redir_out(t_cmd_node *node);
t_cmd_node	*remove_redir(t_cmd_node *head);

/*
	*** execute commands ***
*/
void		exe_builtin(t_cmd_node	*node);
void		exe_builtin_single(t_cmd_node	*node);
char		*is_valid_cmd(t_cmd_node *node);
char		**string_array(t_cmd_node *node);
int			malloc_fd(int size, int ***fd);
int			malloc_pid(int size, pid_t **pid);
int			malloc_status(int size, int **status);
void		exe_with_pipe(t_cmd_line_list	*cmd_line_list);
void		exe_cmd(t_cmd_line_list *cmd_line_list);

/*
	built-in
*/
void		add_old_pwd(void);
char		*get_value(char *key);
void		export_str(char *str);
char		*get_pwd(void);
void		func_cd(t_cmd_node *head);
void		func_echo(t_cmd_node *head);
void		func_env(void);
void		func_exit_single_cmd(t_cmd_node *head);
void		func_exit(t_cmd_node *head);
int			is_in_envp(char *str);
void		modify_envp(char *str, int loc);
char		**new_export(char *str);
int			is_right_form(char *str);
void		func_export(t_cmd_node *head);
void		func_pwd(void);
void		func_unset(t_cmd_node *head);
#endif