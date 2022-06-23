/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:35:33 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/23 11:08:49 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	parse_error(int option)
{
	if (option == 1)
		printf("ERROR : ’(\") must be paired\n");
	else if (option == 2)
		printf("ERROR : Memory allocation failed\n");
	else if (option == 3)
	{
		g_state.exit_status = 258;
		printf("syntax error near unexpected token\n");
	}
	else if (option == 4)
	{
		printf("ERROR : Invaild pipe\n");
	}
	else if (option == 5)
	{
		printf("ERROR : Failed to open file\n");
	}
	return (FALSE);
}

static void	free_token_line(t_token_node *head, char *line)
{
	t_token_node	*curr;
	t_token_node	*temp;

	curr = head;
	while (curr != NULL)
	{
		temp = curr;
		free(curr->token);
		curr = curr->next;
		free(temp);
	}
	if (line != NULL)
		free(line);
}

static int	is_empty_line(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] != '\0' && !(line[idx] == ' ' || \
			line[idx] >= 9 && line[idx] <= 13))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static void	read_cmd_line(char **line)
{
	set_main_signal();
	*line = readline("\033[0;36mMinishell>> \033[0m");
	if (*line == NULL)
	{
		ft_putstr_fd("\x1b[1A", 1);
		ft_putstr_fd("\033[12C", 1);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
}

int	parse_cmd(t_cmd_line_list **cmd_line_list)
{
	char			*line;
	t_token_node	*token_head;

	token_head = NULL;
	ft_memset(*cmd_line_list, 0, sizeof(t_cmd_line_list));
	read_cmd_line(&line);
	if (is_empty_line(line) == TRUE)
	{
		free_token_line(token_head, line);
		return (FALSE);
	}
	add_history(line);
	if (make_token_list(&token_head, line) == FALSE)
	{
		free_token_line(token_head, line);
		return (parse_error(2));
	}
	if (make_cmd_list(cmd_line_list, token_head, line) == FALSE)
	{
		free_token_line(token_head, line);
		return (FALSE);
	}
	free_token_line(token_head, line);
	return (TRUE);
}
