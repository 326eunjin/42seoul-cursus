/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:25:47 by ejang             #+#    #+#             */
/*   Updated: 2022/08/24 21:18:42 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_map(t_cub *cub)
{
	for(int i = 0 ;i< cub->map->map_height;i++)
		for(int j = 0; j <cub->map->map_width;j++)
			if (cub->map->map[i][j] == 'N')
			{
				cub->info->pos_x = (double) j + 0.1;
				cub->info->pos_y = (double) i + 0.1;
			}
}

void	check_cub(t_cub *cub)
{
	// check_info(cub);
	check_map(cub);
	//유효성 확인 끝
	cub->map->f_color = ft_cal_color(cub->map->f);
	cub->map->c_color = ft_cal_color(cub->map->c);
}
