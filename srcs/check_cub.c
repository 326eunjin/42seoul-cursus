/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:25:47 by ejang             #+#    #+#             */
/*   Updated: 2022/08/23 21:36:29 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_map(t_cub *cub)
{
	for(int i = 0 ;i< cub->map->map_height;i++)
		for(int j = 0; j <cub->map->map_width;j++)
			if (cub->map->map[i][j] == 'N')
			{
				cub->info->pos_x = (double) j;
				cub->info->pos_y = (double) i;
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
