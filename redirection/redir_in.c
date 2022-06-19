/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:04:20 by ejang             #+#    #+#             */
/*   Updated: 2022/06/19 16:31:25 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *has_redir_in(t_cmd_node *node)
{
	t_cmd_node *curr;
	t_cmd_node *last_redirin;
	int flag;
	struct stat file_info;
	int cnt;

	cnt = 0;
	flag = FALSE;
	curr = node;
	while (curr != NULL) //갯수 확인
	{
		if (node->type == REDIRIN)
			cnt++;
		curr = curr->next;
	}
	if (cnt == 0)
		return (NULL);
	curr = node;
	while (curr != NULL)
	{
		if (curr->type == REDIRIN)
		{
			//있는지 확인
			if (stat(curr->next->cmd, &file_info) == -1) // bash: 2: No such file or directory
			{
				if (flag == FALSE)
				{
					flag = TRUE;
					ft_putstr_fd("bash: ", STDERR_FILENO);
					ft_putstr_fd(curr->next->cmd, STDERR_FILENO);
					ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
				}
			}
			last_redirin = curr;
		}
		curr = curr->next;
	}
	if (stat(last_redirin->next->cmd, &file_info) == -1) // bash: 2: No such file or directory
	{
		if (flag == FALSE)
		{
			flag = TRUE;
			ft_putstr_fd("bash: ", STDERR_FILENO);
			ft_putstr_fd(curr->next->cmd, STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		}
		exit(1);
	}
	return (last_redirin->next->cmd);
}