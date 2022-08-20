/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:05:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/20 20:39:18 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

void	free_split(char **tmp)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (tmp[++i])
		cnt++;
	i = -1;
	while (++i < cnt)
		free(tmp[i]);
	free(tmp);
	tmp = NULL;
}

void	print_error(char *msg)
{
	printf("%s", "Error\n");
	printf("%s\n", msg);
	exit(1);
}

void	pass_empty_line(int fd, char **line, unsigned int *map_loc)
{
	*line = get_next_line(fd);
	while (*line != NULL && (ft_strncmp(*line, "\n", ft_strlen("\n")) == 0 \
		|| is_space_line(line) == 0))
	{
		*map_loc = *map_loc + 1;
		free(*line);
		*line = get_next_line(fd);
	}
}

int	pass_empty_line_map(int fd, char **line)
{
	int	flag;

	flag = 0;
	*line = get_next_line(fd);
	while (*line != NULL && (ft_strncmp(*line, "\n", ft_strlen("\n")) == 0 \
		|| is_space_line(line) == 0))
	{
		flag = 1;
		printf("%s\n", *line);
		free(*line);
		*line = get_next_line(fd);
	}
	if (*line != NULL && flag == 1)
		return (1);
	else
		return (0);
}
