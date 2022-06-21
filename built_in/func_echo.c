/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:04:10 by ejang             #+#    #+#             */
/*   Updated: 2022/06/21 10:44:05 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	func_echo(t_cmd_node *head)
{
	t_cmd_node	*curr_node;
	int			flag;

	curr_node = head->next;
	if (curr_node->type == OPTION)
	{
		flag = TRUE;
		curr_node = curr_node->next;
	}
	else
		flag = FALSE;
	while (curr_node->next != NULL)
	{
		printf("%s ", curr_node->cmd);
		curr_node = curr_node->next;
	}
	printf("%s", curr_node->cmd);
	if (flag == FALSE)
		printf("\n");
}
