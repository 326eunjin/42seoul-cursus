/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:35:33 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/15 17:45:03 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	if (line == NULL || is_empty_line(line) == TRUE)
	{
		printf("is empty line\n");
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (FALSE);
	}
	add_history(line);
	if (make_token_list(&token_head, line) == FALSE)
	{
		printf("token_error\n");
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (FALSE);
	}
	// *** 디버깅용 프린트
	t_token_node *curr_token = token_head;
	while(curr_token != NULL)
	{
		printf("token : %s (type : %s) (idx : %d)\n", curr_token->token, to_types[curr_token->type], curr_token->idx);
		curr_token = curr_token->next;
	}
	// *** 끝
	// 3. 토큰 리스트를 돌면서 합칠 수 있는건 합치고, 쪼개야 하는건 쪼개기
	if (make_cmd_list(cmd_line_list, token_head, line) == FALSE)
	{
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		printf("argument error\n");
		return (FALSE);
	}
	// 4. 썼던 토큰 리스트 free
	//free_token_list(token_head);
	// 5. true 반환
	return (TRUE);
}