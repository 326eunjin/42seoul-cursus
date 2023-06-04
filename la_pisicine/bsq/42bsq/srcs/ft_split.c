/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:01:36 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 07:10:45 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	split_line(t_map *map_s)
{
	char	*str_cp;
	int		obstacle;
	int		i;

	str_cp = map_s->str;
	obstacle = 0;
	i = 0;
	while (*str_cp != 0)
	{
		if (*str_cp == '\n')
			str_cp++;
		else
		{
			split_line2(map_s, &str_cp, &obstacle, &i);
			i++;
		}
	}
	if (obstacle < 1)
		ft_split_error(map_s, map_s->line_num);
}

void	split_line2(t_map *map_s, char **str_cp, int *obstacle, int *i)
{
	int	j;

	j = 0;
	while (**str_cp != 0 && **str_cp != '\n')
	{
		if (ft_map_check(map_s, **str_cp))
		{
			if (**str_cp == map_s->map_char[1])
			{
				map_s->int_map[*i][j] = 0;
				(*obstacle)++;
			}
			else
				map_s->int_map[*i][j] = -1;
			j++;
		}
		else
			ft_split_error(map_s, map_s->line_num);
		(*str_cp)++;
	}
}

void	malloc_line(t_map *map_s)
{
	char	*str_cp;
	int		size;
	int		i;

	str_cp = map_s->str;
	i = -1;
	while (*str_cp != 0)
	{
		if (*str_cp == '\n')
			str_cp++;
		else
		{
			size = 0;
			while (*str_cp != 0 && *str_cp != '\n')
			{
				size++;
				str_cp++;
			}
			if (size == map_s->line_size)
				map_s->int_map[++i] = (int *)malloc(sizeof(int) * size);
			else
				ft_split_error(map_s, map_s->line_num);
		}
	}
}

int		count_line(t_map *map_s)
{
	char	*str_cp;
	int		count;

	str_cp = map_s->str;
	count = 0;
	while (*str_cp != 0)
	{
		if (*str_cp == '\n')
			str_cp++;
		else
		{
			count++;
			while (*str_cp != 0 && *str_cp != '\n')
				str_cp++;
		}
	}
	return (count);
}

void	ft_split(t_map *map_s)
{
	map_s->line_input = count_line(map_s);
	ft_line_check(map_s, map_s->str);
	map_s->int_map = (int **)malloc(sizeof(int *) * map_s->line_input);
	malloc_line(map_s);
	split_line(map_s);
}
