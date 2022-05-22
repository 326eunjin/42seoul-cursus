/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 04:29:33 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:09:46 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_first_line(t_map *map_s, char *file_name)
{
	char	*buf;
	int		fd;
	int		i;

	if (!(buf = (char *)malloc(sizeof(char) * 1042)))
		ft_stdin_error(map_s, 0);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	ft_first_line2(map_s, fd, buf, &i);
	close(fd);
	free(buf);
	buf = 0;
}

void	ft_first_line2(t_map *map_s, int fd, char *buf, int *i)
{
	int	j;

	if (*i < 4)
		ft_file_error(map_s, fd, buf);
	map_s->map_char[0] = buf[*i - 3];
	map_s->map_char[1] = buf[*i - 2];
	map_s->map_char[2] = buf[*i - 1];
	map_s->line_num = 0;
	if (!ft_map_char_check(map_s))
		ft_file_error(map_s, fd, buf);
	j = -1;
	while (++j < *i - 3)
	{
		if ('0' <= buf[j] && buf[j] <= '9')
			map_s->line_num = map_s->line_num * 10 + (buf[j] - '0');
		else
			ft_file_error(map_s, fd, buf);
	}
}

void	ft_second_line(t_map *map_s, int fd, char *free_buf)
{
	char	*buf;
	int		i;

	if (!(buf = (char *)malloc(sizeof(char) * 1042)))
		ft_file_error(map_s, fd, free_buf);
	i = 0;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	free(buf);
	buf = 0;
}

int		ft_total_size(t_map *map_s, char *file_name)
{
	char	*buf;
	int		fd;
	int		total_size;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (!(buf = (char *)malloc(sizeof(char) * 1042)))
		ft_file_error(map_s, fd, 0);
	ft_second_line(map_s, fd, buf);
	total_size = 0;
	i = 0;
	map_s->line_size = 0;
	while (read(fd, &buf[i], 1))
	{
		total_size++;
		if (buf[i++] == '\n')
			break ;
		map_s->line_size++;
	}
	while (read(fd, &buf[i++], 1))
		total_size++;
	close(fd);
	free(buf);
	buf = 0;
	return (total_size);
}

void	ft_total_str(t_map *map_s, char *file_name)
{
	char	*buf;
	int		fd;
	int		total_size;
	int		i;

	fd = open(file_name, O_RDONLY);
	ft_second_line(map_s, fd, 0);
	total_size = ft_total_size(map_s, file_name);
	if (!(buf = (char *)malloc(sizeof(char) * (total_size + 1))))
		ft_file_error(map_s, fd, 0);
	i = -1;
	while (++i < total_size)
		read(fd, &buf[i], 1);
	buf[i] = 0;
	close(fd);
	map_s->str = buf;
}
