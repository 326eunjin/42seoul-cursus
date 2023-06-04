/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeukim <yeukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 05:18:58 by yeukim            #+#    #+#             */
/*   Updated: 2021/04/15 10:50:35 by yeukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		main(int argc, char *argv[])
{
	t_map	*map_s;
	int		i;

	if (argc == 1)
	{
		map_s = (t_map *)malloc(sizeof(t_map) * 1);
		ft_first_stdin(map_s);
		ft_total_stdin(map_s);
		ft_run(map_s, map_s->line_num);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			map_s = (t_map *)malloc(sizeof(t_map) * 1);
			ft_first_line(map_s, argv[i]);
			ft_total_str(map_s, argv[i]);
			ft_run(map_s, map_s->line_num);
			write(1, "\n", 1);
		}
	}
	return (0);
}

void	ft_run(t_map *map_s, int index)
{
	ft_split(map_s);
	ft_solve(map_s);
	ft_bsq(map_s);
	ft_print_map(map_s);
	ft_memory_free(map_s, index);
	free(map_s);
}
