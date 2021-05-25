/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 03:33:15 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:10:16 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_line_check(t_map *map_s, char *buf)
{
	if ((map_s->line_input != map_s->line_num) || (map_s->line_num < 1))
	{
		free(buf);
		ft_putstr(ERROR);
		exit(0);
	}
}

int		ft_map_check(t_map *map_s, char ch)
{
	if (ch == map_s->map_char[0] || ch == map_s->map_char[1])
		return (1);
	return (0);
}

int		ft_map_char_check(t_map *map_s)
{
	int	duplicate_flag;
	int	printable_flag;
	int	i;

	duplicate_flag = 0;
	printable_flag = 0;
	if ((map_s->map_char[0] == map_s->map_char[1]) ||
		(map_s->map_char[0] == map_s->map_char[2]) ||
		(map_s->map_char[1] == map_s->map_char[2]))
	{
		duplicate_flag = 1;
	}
	i = -1;
	while (++i < 3)
	{
		if (map_s->map_char[i] < 32 || 126 < map_s->map_char[i])
			printable_flag = 1;
	}
	if (duplicate_flag || printable_flag)
		return (0);
	return (1);
}
