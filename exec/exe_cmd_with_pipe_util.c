/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_with_pipe_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:44:26 by ejang             #+#    #+#             */
/*   Updated: 2022/06/23 19:57:38 by ejang            ###   ########.fr       */
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
			return (FALSE);
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
		return (FALSE);
	ft_memset(*pid, 0, sizeof(*pid));
	return (TRUE);
}

int	malloc_status(int size, int **status)
{
	int	i;

	i = 0;
	*status = (int *)malloc(sizeof(int *) * size);
	if (*status == NULL)
		return (FALSE);
	ft_memset(*status, 0, sizeof(*status));
	return (TRUE);
}

void	malloc_variables(int size, int ***fd, pid_t **pid, int **status)
{
	if (malloc_fd(size - 1, fd) == FALSE || malloc_pid \
	(size, pid) == FALSE || malloc_status(size, status) == FALSE)
	{
		g_state.exit_status = 1;
		exit(1);
	}
}
