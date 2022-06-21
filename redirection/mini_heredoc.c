/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:35:18 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/22 02:14:47 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	write_dollar_heredoc(char *line, int start, int len, int fd)
{
	char	*name;
	char	*value;

	name = ft_substr(line, start, len);
	if (name == NULL)
	{
		write(fd, "\n", 1);
		return (parse_error(2));
	}
	value = replace_dollar(name, start, line);
	if (value == NULL)
	{
		free(name);
		write(fd, "\n", 1);
		return (parse_error(2));
	}
	ft_putstr_fd(value, fd);
	free(name);
	free(value);
	return (TRUE);
}

static int	write_heredoc(int fd, char *line)
{
	int		idx;
	int		temp;
	char	*name;
	char	*value;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '$')
		{
			temp = ++idx;
			while (line[idx] != '\0' && !(line[idx] == ' ' || \
				line[idx] >= 9 && line[idx] <= 13))
				idx++;
			if (write_dollar_heredoc(line, temp, idx - temp, fd) == FALSE)
				return (FALSE);
		}
		else
		{
			ft_putchar_fd(line[idx], fd);
			idx++;
		}
	}
	write(fd, "\n", 1);
	return (TRUE);
}

static void	finish_heredoc(t_cmd_node **curr_cmd, int fd)
{
	(*curr_cmd)->prev->type = REDIRIN;
	free((*curr_cmd)->cmd);
	(*curr_cmd)->cmd = ft_strdup("heredoc");
	close(fd);
}

int	mini_heredoc(t_cmd_node **curr_cmd)
{
	char	*line;
	int		fd;

	fd = open("heredoc", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (parse_error(5));
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
		if (write_heredoc(fd, line) == FALSE)
		{
			free(line);
			return (FALSE);
		}
		free(line);
	}
	finish_heredoc(curr_cmd, fd);
	return (TRUE);
}
