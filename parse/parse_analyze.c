/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_analyze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:38 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/07 15:52:18 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	void	token_analyze(t_cmd_line *cmd_line)	:	cmd에 따라서 type 설정해주는 함수.
		- pipe : PIPE
		- quote : DQUOTE, QUOTE
		- redirection : REDIRIN, REDIROUT, APPEND, HEREDOC
		- bulitin command : BUILTIN
		- 그 외 : 일단은 ARG
	static int	is_bulitin(char *cmd)	:	cmd가 bulitin 함수인지 확인
	static int	ft_strcmp(char *s1, char *s2)	:	단순 ft_strcmp. (libft에는 ft_strncmp가 있다.)
*/

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	is_bulitin(char *cmd)
{
	if ((!ft_strcmp(cmd, "echo")) || (!ft_strcmp(cmd, "cd")) \
	|| (!ft_strcmp(cmd, "pwd")) || (!ft_strcmp(cmd, "export")) \
	|| (!ft_strcmp(cmd, "unset")) || (!ft_strcmp(cmd, "env")) \
	|| (!ft_strcmp(cmd, "exit")))
		return (0);
	return (1);
}

void	token_analyze(t_cmd_line *cmd_line)
{
	t_cmd_node	*curr;

	curr = cmd_line->head;
	while (curr != NULL)
	{
		if (ft_strcmp(curr->cmd, "|") == 0)
			curr->type = PIPE;
		else if (curr->cmd[0] == '"')
			curr->type = DQUOTE;
		else if (curr->cmd[0] == '\'')
			curr->type = QUOTE;
		else if (ft_strcmp(curr->cmd, ">") == 0)
			curr->type = REDIRIN;
		else if (ft_strcmp(curr->cmd, "<") == 0)
			curr->type = REDIROUT;
		else if (ft_strcmp(curr->cmd, ">>") == 0)
			curr->type = APPEND;
		else if (ft_strcmp(curr->cmd, "<<") == 0)
			curr->type = HEREDOC;
		else if (is_bulitin(curr->cmd) == 0)
			curr->type = BUILTIN;
		else
			curr->type = ARG;
		curr = curr->next;
	}
}
