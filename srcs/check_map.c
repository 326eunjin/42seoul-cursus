/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:30:34 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/25 19:45:54 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>

void	init_pos_dir(int y, int x, t_cub *cub, int *player_flag)
{
	cub->info->pos_y = (double)(y) + 0.5;
	cub->info->pos_x = (double)(x) + 0.5;
	if (cub->map->map[y][x] == 'N')
	{
		cub->info->plane_x = 0.66;
		cub->info->dir_y = 1;
	}
	else if (cub->map->map[y][x] == 'S')
	{	
		cub->info->plane_x = -0.66;
		cub->info->dir_y = -1;
	}
	else if (cub->map->map[y][x] == 'E')
	{
		cub->info->plane_y = -0.66;
		cub->info->dir_x = 1;
	}
	else
	{
		cub->info->plane_y = 0.66;
		cub->info->dir_x = -1;
	}
	cub->map->map[y][x] = '0';
	*player_flag = 1;
}

void	check_closed(t_cub *cub, int y, int x)
{
	if (cub->map->map[y][x] == '0')
	{
		if (y <= 0 || y >= cub->map->map_height - 1 \
			|| x <= 0 || x >= cub->map->map_width - 1)
			print_error("Map must be closed/surrounded by walls");
		if (cub->map->map[y - 1][x] == ' ')
			print_error("Map must be closed/surrounded by walls");
		if (cub->map->map[y + 1][x] == ' ')
			print_error("Map must be closed/surrounded by walls");
		if (cub->map->map[y][x - 1] == ' ')
			print_error("Map must be closed/surrounded by walls");
		if (cub->map->map[y][x + 1] == ' ')
			print_error("Map must be closed/surrounded by walls");
	}
	return ;
}

void	check_map(t_cub *cub)
{
	int	i;
	int	j;
	int	player_flag;

	i = -1;
	player_flag = 0;
	while (++i < cub->map->map_height)
	{
		j = -1;
		while (++j < cub->map->map_width)
		{
			if (ft_strchr("10 NSEW", cub->map->map[i][j]) == NULL)
				print_error("Map can contain N, S, E, W, 1, 0, space");
			check_closed(cub, i, j);
			if (ft_strchr("NSEW", cub->map->map[i][j]) != NULL)
			{	
				if (player_flag == 1)
					print_error("Maps must contain only one player");
				init_pos_dir(i, j, cub, &player_flag);
			}
		}
	}
	if (player_flag == 0)
		print_error("Map must contain at least one player");
}
