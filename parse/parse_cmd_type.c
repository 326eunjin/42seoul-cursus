/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:21:28 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/22 00:26:35 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_echo_option(t_cmd_node *node)
{
	int	idx;

	if (node != NULL && node->cmd[0] == '-')
	{
		idx = 1;
		while (node->cmd[idx] != '\0')
		{
			if (node->cmd[idx] != 'n')
				return (FALSE);
			idx++;
		}
		return (TRUE);
	}
	return (FALSE);
}

static int	is_builtin(t_cmd_node **curr)
{
	int		ret;
	char	*temp;

	temp = get_lower_str((*curr)->cmd);
	ret = FALSE;
	if (ft_strcmp(temp, "echo") == 0)
	{
		(*curr)->type = BUILTIN;
		if (is_echo_option((*curr)->next) == TRUE)
		{
			*curr = (*curr)->next;
			(*curr)->type = OPTION;
		}
		ret = TRUE;
	}
	else if (!ft_strcmp(temp, "cd") || !ft_strcmp(temp, "pwd") || \
		!ft_strcmp(temp, "export") || !ft_strcmp(temp, "unset") || \
		!ft_strcmp(temp, "env") || !ft_strcmp(temp, "exit"))
	{
		(*curr)->type = BUILTIN;
		ret = TRUE;
	}
	free(temp);
	return (ret);
}

static void	write_heredoc(int fd, char *line)
{
	int		idx;
	int		temp;
	char	*key;

	idx = -1;
	while (line[++idx] != '\0')
	{
		if (line[idx] == '$')
		{
			temp = ++idx;
			while (line[idx] != '\0' && line[idx] != ' ' && line[idx] != '$')
				idx++;
			if (temp == idx++)
			{
				ft_putchar_fd('$', fd);
				continue ;
			}
			key = ft_substr(line, temp, (--idx) - temp + 1);
			if (is_in_envp(key) != -1)
				ft_putstr_fd(get_value(key), fd);
			free(key);
		}
		else
			ft_putchar_fd(line[idx], fd);
	}
}

static int	mini_heredoc(t_cmd_node **curr_cmd)
{
	char	*line;
	int		fd;

	fd = open("heredoc", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (FALSE);
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			move_heredoc_curser();
		if (line == NULL || ft_strcmp(line, (*curr_cmd)->cmd) == 0)
		{
			free(line);
			break ;
		}
		write_heredoc(fd, line);
		//write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	(*curr_cmd)->prev->type = REDIRIN;
	free((*curr_cmd)->cmd);
	(*curr_cmd)->cmd = ft_strdup("heredoc");
	close(fd);
	return (TRUE);
}

static int	check_redir(t_cmd_node **curr_cmd)
{
	enum e_cmd_type	type;

	type = (*curr_cmd)->type;
	if (type == REDIRIN || type == REDIROUT || type == HEREDOC || \
		type == APPEND)
	{
		if ((*curr_cmd)->next == NULL)
			return (parse_error(3));
		else
		{
			*curr_cmd = (*curr_cmd)->next;
			(*curr_cmd)->type = REDIRARG;
		}
	}
	if (type == HEREDOC)
	{
		if (mini_heredoc(curr_cmd) == FALSE)
			return (parse_error(5));
	}
	return (TRUE);
}

int	check_cmd(t_cmd_node **cmd_heads, int size)
{
	int			idx;
	int			flag;
	t_cmd_node	*curr;
	char		*temp;

	idx = 0;
	while (idx < size)
	{
		flag = FALSE;
		curr = cmd_heads[idx];
		while (curr != NULL)
		{
			if (check_redir(&curr) == FALSE)
				return (FALSE);
			if (flag == FALSE && curr->type == COMMON && \
				(is_builtin(&curr) == TRUE))
				tolower_str(curr->cmd);
			if (flag == FALSE && curr->type == COMMON || curr->type == BUILTIN)
				flag = TRUE;
			curr = curr->next;
		}
		idx++;
	}
	return (TRUE);
}
