/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:35:33 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/12 21:07:39 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	{
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (TRUE);
	}
	add_history(line);
	if (make_token_list(&token_head, line) == FALSE)
	{
		//free_token_list(token_head);
		//free_cmd_line_list(cmd_line_list);
		return (FALSE);
	}
	// *** 디버깅용 프린트
	t_token_node *curr_token = token_head;
	while(curr_token != NULL)
	{
		printf("token : %s (type : %s)\n", curr_token->token, to_types[curr_token->type]);
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