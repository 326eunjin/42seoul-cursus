/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:59:00 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/28 16:21:02 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_sqaure(t_cub *cub, int y, int x, int option)
{
	unsigned int	color;
	int				i;
	int				j;

	if (option == 0)
		color = 0X000000;
	else if (option == 1)
		color = 0Xffffff;
	else
		color = 0x00fd00;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			cub->mlx->buf[y * 3 + i][x * 3 + j] = color;
			j++;
		}
		i++;
	}
}

void	mini_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->map->map_height)
	{
		j = 0;
		while (j < cub->map->map_width)
		{
			if (cub->map->map[i][j] == '1')
				draw_sqaure(cub, i, j, 1);
			if (cub->map->map[i][j] == '0')
				draw_sqaure(cub, i, j, 0);
			if (i == (int)cub->info->pos_y && j == (int)cub->info->pos_x)
				draw_sqaure(cub, i, j, 2);
			j++;
		}
		i++;
	}
}
