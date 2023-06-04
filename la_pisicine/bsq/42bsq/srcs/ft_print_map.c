/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:40:27 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:10:25 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_bsq(t_map *map_s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_s->max)
	{
		j = -1;
		while (++j < map_s->max)
		{
			map_s->int_map[map_s->max_row - i][map_s->max_col - j] = -42;
		}
	}
}

void	ft_print_map(t_map *map_s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_s->line_num)
	{
		j = -1;
		while (++j < map_s->line_size)
		{
			if (map_s->int_map[i][j] == -42)
				write(1, &map_s->map_char[2], 1);
			else if (map_s->int_map[i][j] == 0)
				write(1, &map_s->map_char[1], 1);
			else
				write(1, &map_s->map_char[0], 1);
		}
		write(1, "\n", 1);
	}
	map_s->max_row = map_s->max_row + 0;
}
