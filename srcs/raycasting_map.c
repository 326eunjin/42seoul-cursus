/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:18:52 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/21 21:30:14 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <math.h>
#include "../mlx/mlx.h"

void	init_ray2(t_ray *ray, t_cub *cub)
{
	if (ray->ray_dir_x > 0)
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->info->pos_x) \
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->info->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y > 0)
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->info->pos_y) \
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->info->pos_y - ray->map_y) * ray->delta_dist_y;
	}
}

void	init_ray(t_ray *ray, t_cub *cub, int x)
{
	ray->camera_x = (2 * x / (double)SCREEN_WIDTH) - 1;
	ray->ray_dir_x = cub->info->dir_x + cub->info->plane_x * ray->camera_x;
	ray->ray_dir_y = cub->info->dir_y + cub->info->plane_y * ray->camera_x;
	ray->map_x = (int)cub->info->pos_x;
	ray->map_y = (int)cub->info->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	init_ray2(ray, cub);
}

void	dda(t_ray *ray, t_cub *cub)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (cub->map->map[ray->map_x][ray->map_y] > '0')
			ray->hit = 1;// 왜 여기선 [x][y] 인지 ?
	}
}

void	cal_line(t_ray *ray, t_draw *draw)
{
	draw->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw->draw_end >= SCREEN_HEIGHT)
		draw->draw_end = SCREEN_HEIGHT - 1;
}

void	cal_ray(t_ray *ray, t_cub *cub, t_draw *draw)
{
	double	wall_x;

	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->map_x - cub->info->pos_x + \
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - cub->info->pos_y + \
		(1 - ray->step_y) / 2) / ray->ray_dir_y;
	cal_line(ray, draw);
	draw->tex_num = ray->side;
	if (ray->side == 0 || ray->side == 1)
		wall_x = cub->info->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = cub->info->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (((ray->side == 0) || (ray->side == 1)) && ray->ray_dir_x > 0)
		draw->tex_x = TEX_WIDTH - draw->tex_x - 1;
	if (((ray->side == 2) || (ray->side == 3)) && ray->ray_dir_y < 0)
		draw->tex_x = TEX_HEIGHT - draw->tex_x - 1;
	return ;
}
