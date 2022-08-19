/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:49:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/19 21:59:58 by ejang            ###   ########.fr       */
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
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
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
	printf("%s\n",map.no);
	printf("%s\n",map.so);
	printf("%s\n",map.we);
	printf("%s\n",map.ea);
	printf("%s\n",map.f);
	printf("%s\n",map.c);
	printf("---\n");
	for(int i = 0; i < (int)map.map_height; i++)
	{
		for(int j = 0; j < (int)map.map_width; j++)
			printf("%c ", map.map[i][j]);
		printf("\n");
	}
}
