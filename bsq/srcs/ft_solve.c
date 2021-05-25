/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 06:55:40 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:09:56 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_init(t_map *map_s)
{
	int	i;

	i = -1;
	while (++i < map_s->line_size)
	{
		if (map_s->int_map[0][i] != 0)
			map_s->int_map[0][i] = 1;
	}
	i = -1;
	while (++i < map_s->line_num)
	{
		if (map_s->int_map[i][0] != 0)
			map_s->int_map[i][0] = 1;
	}
}

void	ft_map_init(t_map *map_s)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map_s->line_num)
	{
		j = 0;
		while (++j < map_s->line_size)
		{
			if (map_s->int_map[i][j] != 0)
				map_s->int_map[i][j] = ft_min(map_s, i, j) + 1;
		}
	}
}

int		ft_min(t_map *map_s, int row, int col)
{
	int	min;

	min = map_s->int_map[row - 1][col - 1];
	if (map_s->int_map[row][col - 1] < min)
		min = map_s->int_map[row][col - 1];
	else if (map_s->int_map[row - 1][col] < min)
		min = map_s->int_map[row - 1][col];
	return (min);
}

void	ft_find_max(t_map *map_s)
{
	int	i;
	int	j;

	map_s->max = -1;
	i = -1;
	while (++i < map_s->line_num)
	{
		j = -1;
		while (++j < map_s->line_size)
		{
			if (map_s->int_map[i][j] > map_s->max)
			{
				map_s->max = map_s->int_map[i][j];
				map_s->max_row = i;
				map_s->max_col = j;
			}
		}
	}
}

void	ft_solve(t_map *map_s)
{
	ft_init(map_s);
	ft_map_init(map_s);
	ft_find_max(map_s);
}
