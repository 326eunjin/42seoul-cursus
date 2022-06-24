/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_with_pipe_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:44:26 by ejang             #+#    #+#             */
/*   Updated: 2022/06/24 21:32:17 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	malloc_fd(int size, int ***fd)
{
	int	i;

	i = 0;
	*fd = (int **)malloc(sizeof(int *) * size);
	if (*fd == NULL)
		return (FALSE);
	ft_memset(*fd, 0, sizeof(*fd));
	while (i < size)
	{
		(*fd)[i] = (int *)malloc(sizeof(int) * 2);
		if ((*fd)[i] == NULL)
		{
			free_array((*fd), i);
			return (FALSE);
		}
		ft_memset((*fd)[i], 0, sizeof((*fd)[i]));
		i++;
	}
	return (TRUE);
}

int	malloc_pid(int size, pid_t **pid)
{
	int	i;

	i = 0;
	*pid = (pid_t *)malloc(sizeof(pid_t *) * size);
	if (*pid == NULL)
		exit (1);
	ft_memset(*pid, 0, sizeof(*pid));
	return (TRUE);
}

int	malloc_status(int size, int **status)
{
	int	i;

	i = 0;
	*status = (int *)malloc(sizeof(int *) * size);
	if (*status == NULL)
		exit(1);
	ft_memset(*status, 0, sizeof(*status));
	return (TRUE);
}

void	malloc_variables(int size, int ***fd, pid_t **pid, int **status)
{
	if (malloc_fd(size - 1, fd) != TRUE || malloc_pid \
	(size, pid) != TRUE || malloc_status(size, status) != TRUE)
	{
		g_state.exit_status = 1;
		exit(1);
	}
}

void	execve_error(char *strerror, t_cmd_node *cmd_list)
{
	if (ft_strcmp(strerror, "Bad address") == 0)
	{
		ft_putstr_fd("bash : ", STDERR_FILENO);
		ft_putstr_fd(cmd_list->cmd, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(127);
	}
	else if (ft_strcmp(strerror, "Permission denied") == 0)
	{
		ft_putstr_fd("bash : ", STDERR_FILENO);
		ft_putstr_fd(cmd_list->cmd, STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
		exit(126);
	}
}