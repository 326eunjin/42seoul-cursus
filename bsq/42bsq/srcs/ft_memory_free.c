/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 05:44:04 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:09:35 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_memory_free(t_map *map_s, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(map_s->int_map[i]);
		map_s->int_map[i] = 0;
		i++;
	}
	free(map_s->int_map);
	map_s->int_map = 0;
	free(map_s->str);
	map_s->str = 0;
}

void	ft_file_error(t_map *map_s, int fd, char *buf)
{
	close(fd);
	free(buf);
	buf = 0;
	free(map_s);
	ft_putstr(ERROR);
	exit(0);
}

void	ft_stdin_error(t_map *map_s, char *buf)
{
	free(buf);
	buf = 0;
	free(map_s);
	map_s = 0;
	ft_putstr(ERROR);
	exit(0);
}

void	ft_split_error(t_map *map_s, int index)
{
	ft_memory_free(map_s, index);
	ft_putstr(ERROR);
	exit(0);
}
