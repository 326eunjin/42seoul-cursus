/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:35:33 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/16 21:31:19 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	parse_error(int option)
{
	if (option == 1)
		printf("’(\") must be paired\n");
	if (option == 2)
		printf("Memory allocation failed\n");
	if (option == 3)
		printf("syntax error near unexpected token\n");
	return (FALSE);
}

static void	free_token(t_token_node *head)
{
	t_token_node	*curr;

	curr = head;
	while (curr != NULL)
	{
		free(curr->token);
		free(curr);
		curr = curr->next;
	}
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

static int	shell_exit(t_cmd_line_list **cmd_line_list)
{
	// free(cmd_line_list)
	printf("exit\n");
	exit(0);
}

int	parse_cmd(t_cmd_line_list **cmd_line_list)
{
	char			*line;
	t_token_node	*token_head;

	*cmd_line_list = (t_cmd_line_list *)malloc(sizeof(t_cmd_line_list));
	if (*cmd_line_list == NULL)
		return (FALSE);
	token_head = NULL;
	ft_memset(*cmd_line_list, 0, sizeof(t_cmd_line_list));
	line = readline("\033[0;36mMinishell>> \033[0m");
	if (line == NULL)
		return (shell_exit(cmd_line_list));
	if (is_empty_line(line) == TRUE)
	{
		printf("is empty line\n");
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (FALSE);
	}
	add_history(line);
	if (make_token_list(&token_head, line) == FALSE)
	{
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (parse_error(2));
	}
	// 3. 토큰 리스트를 돌면서 합칠 수 있는건 합치고, 쪼개야 하는건 쪼개기
	if (make_cmd_list(cmd_line_list, token_head, line) == FALSE)
	{
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (FALSE);
	}
	// 4. 썼던 토큰 리스트 free
	free_token(token_head);
	free(line);
	// 5. true 반환
	return (TRUE);
}