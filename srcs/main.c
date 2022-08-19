/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:49:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/19 17:05:59 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_info	info;

	if (argc != 2)
	{
		printf("Argc must be two\n");
		exit(1);
	}
	parse_main(&map, &info, argv[1]);
}
