/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:52:30 by ejang             #+#    #+#             */
/*   Updated: 2022/06/20 17:15:03 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*without_redir(t_cmd_node *node)
{
	t_cmd_node *curr = node;
	char *ret;

	ret = NULL;
	while(curr!=NULL)
	{
		if (curr->type == COMMON)//ls -al
		{
			ret = ft_strjoin(ret , ft_strdup(curr->cmd)); // "ls"
			ret = ft_strjoin(ret, ft_strdup(" "));// "ls "
		}
		curr = curr->next;
	}
	return (ret);
}

char	*is_valid_cmd_redir(char *ret)//ret = ls -al
{
	char* tmp;
	struct stat s;
	char **path = ft_split(get_value("PATH"), ':');
	char **ret_arr;
	int i = -1;
	
	tmp = ft_strdup(ret);//ls -al
	free(ret);
	ret_arr = ft_split(tmp, ' ');
	free(tmp);
	tmp = ft_strdup(ret_arr[0]);
	if (stat(tmp, &s) == 0)
		return (tmp);
	while(path[++i])
	{
		tmp = ft_strjoin(ft_strdup("/"),tmp);
		tmp = ft_strjoin(ft_strdup(path[i]),tmp);
		if (stat(tmp, &s) == 0)
		{
			free_split(ret_arr);
			free_split(path);
			return (tmp);
		}
		tmp = ft_strdup(ret_arr[0]);
	}
	free_split(ret_arr);
	free_split(path);
	return (NULL);
}
