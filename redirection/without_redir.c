/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:52:30 by ejang             #+#    #+#             */
/*   Updated: 2022/06/21 00:55:48 by jeyoon           ###   ########seoul.kr  */
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

void	free_single_cmd_list(t_cmd_node *head)
{
	t_cmd_node	*curr;
	t_cmd_node	*temp;

	curr = head;
	while (curr != NULL)
	{
		temp = curr;
		if (curr->cmd != NULL)
			free(curr->cmd);
		curr = curr->next;
		free(temp);
	}
}

static t_cmd_node	*cmd_dup(t_cmd_node *src_node)
{
	t_cmd_node	*new_node;

	new_node = (t_cmd_node *)malloc(sizeof(t_cmd_node));
	if (new_node == NULL)
		return (NULL);
	ft_memset(new_node, 0, sizeof(t_cmd_node));
	new_node->cmd = ft_strdup(src_node->cmd);
	if (new_node->cmd == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->type = src_node->type;
	return (new_node);
}

t_cmd_node *remove_redir(t_cmd_node *head)
{
	t_cmd_node	*new_list_head;
	t_cmd_node	*new_node;
	t_cmd_node	*curr;

	new_list_head = NULL;
	curr = head;
	while (curr != NULL)
	{
		if (curr->type == COMMON || curr->type == BUILTIN \
			|| curr->type == OPTION)
		{
			new_node = cmd_dup(curr);
			if (new_node == NULL || add_cmd(&new_list_head, new_node) == FALSE)
			{
				free_single_cmd_list(new_list_head);
				return (NULL);
			}
		}
		curr = curr->next;
	}
	return (new_list_head);
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
