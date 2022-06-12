/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:04:10 by ejang             #+#    #+#             */
/*   Updated: 2022/06/12 21:48:14 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//void	echo(int flag, char *str)
void	func_echo(t_cmd_node *head)
//아직 합친게 아니라서 flag가 n 옵션이 있는지 아닌지 확인하는겁니다,,!
{
	t_cmd_node *curr_node;
	int			flag;

	curr_node = head->next;
	if (curr_node->type == OPTION)
	{
		flag = TRUE;
		curr_node = curr_node->next;
	}
	else
		flag = FALSE;
	while(curr_node->next != NULL)
	{
		printf("%s ", curr_node->cmd);
		curr_node = curr_node->next;
	}
	printf("%s",curr_node->cmd);
	if (flag == FALSE)
		printf("\n");
}
