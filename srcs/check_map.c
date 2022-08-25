/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:30:34 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/25 12:31:26 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <stdio.h>

void	init_pos_dir(int y, int x, t_cub *cub, int *player_flag)
{
	cub->info->pos_y = (double)(y) + 0.1;
	cub->info->pos_x = (double)(x) + 0.1;
	if (cub->map->map[y][x] == 'N')
	{
		cub->info->dir_y = -1.0;
		cub->info->plane_x = 0.66;
	}
	else if (cub->map->map[y][x] == 'S')
	{	
		cub->info->dir_y = 1.0;
		cub->info->plane_x = -0.66;
	}
	else if (cub->map->map[y][x] == 'E')
	{
		cub->info->dir_x = 1.0;
		cub->info->plane_y = 0.66;
	}
	else
	{
		cub->info->dir_x = -1.0;
		cub->info->plane_y = -0.66;
	}
	cub->map->map[y][x] = '0';
	*player_flag = 1;
}

void	check_map(t_cub *cub)
{
	int	i;
	int	j;
	int	player_flag;

	i = 0;
	player_flag = 0;
	while (i < cub->map->map_height)
	{
		j = 0;
		while (j < cub->map->map_width)
		{
			if (ft_strchr("10 NSEW", cub->map->map[i][j]) == NULL)
				print_error("Map can contain 'N', 'S', 'E', 'W', '1', '0', space");
			// 닫혀 있는지 확인
			if (ft_strchr("NSEW", cub->map->map[i][j]) != NULL)
			{	
				if (player_flag == 1)
					print_error("Maps must contain only one player");
				init_pos_dir(i, j, cub, &player_flag);
			}
			j++;
		}
		i++;
	}
	printf("posX\t: %f,\tposY\t: %f\n", cub->info->pos_x, cub->info->pos_y);
	printf("dirX\t: %f,\tdirY\t: %f\n", cub->info->dir_x, cub->info->dir_y);
	printf("planeX\t: %f,\tplaneY\t: %f", cub->info->plane_x, cub->info->plane_y);
}