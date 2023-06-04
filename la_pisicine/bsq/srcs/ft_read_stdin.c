/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 00:05:54 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:10:36 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_first_stdin(t_map *map_s)
{
	char	*buf;
	int		i;

	if (!(buf = (char *)malloc(sizeof(char) * 1042)))
		ft_stdin_error(map_s, 0);
	i = -1;
	while (read(0, &buf[++i], 1))
	{
		if (buf[i] == '\n')
			break ;
	}
	ft_first_stdin2(map_s, buf, i);
	free(buf);
	return (1);
}

void	ft_first_stdin2(t_map *map_s, char *buf, int i)
{
	int	j;

	if (i < 4)
		ft_stdin_error(map_s, buf);
	map_s->map_char[0] = buf[i - 3];
	map_s->map_char[1] = buf[i - 2];
	map_s->map_char[2] = buf[i - 1];
	map_s->line_num = 0;
	if (!ft_map_char_check(map_s))
		ft_stdin_error(map_s, buf);
	j = -1;
	while (++j < i - 3)
	{
		if ('0' <= buf[j] && buf[j] <= '9')
			map_s->line_num = map_s->line_num * 10 + (buf[j] - '0');
		else
			ft_stdin_error(map_s, buf);
	}
}

void	ft_total_stdin(t_map *map_s)
{
	char			*buf;
	unsigned int	buf_size;
	unsigned int	i;

	buf_size = 42;
	if (!(buf = (char *)malloc(sizeof(char) * buf_size)))
		ft_stdin_error(map_s, 0);
	i = 0;
	map_s->line_size = 0;
	while (read(0, &buf[i], 1))
	{
		if (buf[i++] == '\n')
			break ;
		map_s->line_size++;
		if (i == buf_size - 2)
			buf = ft_expand_buf(map_s, buf, &buf_size);
	}
	while (read(0, &buf[i], 1))
	{
		i++;
		if (i == buf_size - 2)
			buf = ft_expand_buf(map_s, buf, &buf_size);
	}
	buf[i] = 0;
	map_s->str = buf;
}

char	*ft_expand_buf(t_map *map_s, char *buf, unsigned int *buf_size)
{
	char	*new_buf;

	if (!(new_buf = (char *)malloc(sizeof(char) * (*buf_size << 1))))
		ft_stdin_error(map_s, buf);
	ft_strncpy(new_buf, buf, *buf_size);
	*buf_size = *buf_size << 1;
	free(buf);
	return (new_buf);
}
