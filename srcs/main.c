/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:49:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/19 21:16:27 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/cub3d.h"
#include "../mlx/mlx.h"

void init_struct(t_map *map, t_info *info)
{
	// MAP 초기화
	map->map_height = 0;
	map->map_width = 0;
	// info 초기화
	info->dir_x = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_info	info;

	if (argc != 2)
	{
		printf("Argc must be two\n");
		exit(1);
	}
	init_struct(&map, &info);
	parse_main(&map, argv[1]);
	for(int i = 0; i < (int)map.map_height; i++)
	{
		for(int j = 0; j < (int)map.map_width; j++)
			printf("%c ", map.map[i][j]);
		printf("\n");
	}
}
