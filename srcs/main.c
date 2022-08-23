/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:49:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/23 16:58:10 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/cub3d.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_cub	cub;
	t_mlx	mlx;
	t_map	map;
	t_info	info;

	cub.mlx = &mlx;
	cub.map = &map;
	cub.info = &info;
	if (argc != 2)
	{
		printf("Argc must be two\n");
		exit(1);
	}
	init_struct(&cub);
	parse_main(&cub, argv[1]);
	check_map(&cub);
	mlx_struct_init(&cub);
	mlx_loop_hook(cub.mlx->mlx_ptr, &main_loop, &cub);
	mlx_hook(cub.mlx->win_ptr, KEYPRESS, 0, &key_press, &cub);
	mlx_hook(cub.mlx->win_ptr, 17, 0, press_x_button, &mlx);
	mlx_loop(cub.mlx->mlx_ptr);
	return (0);
}
