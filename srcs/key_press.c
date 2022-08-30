/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:17:11 by ejang             #+#    #+#             */
/*   Updated: 2022/08/30 16:39:31 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../inc/cub3d.h"

int	press_x_button(t_cub *cub)
{
	free_map(cub);
	free_mlx(cub);
	exit(0);
	return (0);
}

void	rotate_player(t_info *info, int option)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	if (option == 0)
		angle = info->rot_speed;
	else
		angle = info->rot_speed * (-1);
	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(angle) - info->dir_y * sin(angle);
	info->dir_y = old_dir_x * sin(angle) + info->dir_y * cos(angle);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(angle) - info->plane_y * sin(angle);
	info->plane_y = old_plane_x * sin(angle) + info->plane_y * cos(angle);
}

void	move_front_back(t_map *map, t_info *info, int option)
{
	if (map->map[(int)info->pos_y][(int)(info->pos_x + option * info->dir_x * \
		info->move_speed)] == '0')
		info->pos_x += option * (info->dir_x * info->move_speed);
	if (map->map[(int)(info->pos_y + \
		option * info->dir_y * info->move_speed)][(int)(info->pos_x)] == '0')
		info->pos_y += option * (info->dir_y * info->move_speed);
}

void	move_left_right(t_map *map, t_info *info, int option)
{
	if (map->map[(int)info->pos_y][(int)(info->pos_x + (option * info->plane_x) \
		* info->move_speed)] == '0')
			info->pos_x = info->pos_x + option * \
				(info->plane_x * info->move_speed);
	if (map->map[(int)(info->pos_y + (option * info->plane_y) \
		* info->move_speed)][(int)(info->pos_x)] == '0')
		info->pos_y = info->pos_y + option * (info->plane_y * info->move_speed);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		move_front_back(cub->map, cub->info, 1);
	else if (keycode == KEY_S)
		move_front_back(cub->map, cub->info, -1);
	else if (keycode == KEY_A)
		move_left_right(cub->map, cub->info, -1);
	else if (keycode == KEY_D)
		move_left_right(cub->map, cub->info, 1);
	else if (keycode == KEY_LEFT)
		rotate_player(cub->info, 0);
	else if (keycode == KEY_RIGHT)
		rotate_player(cub->info, 1);
	else if (keycode == KEY_ESC)
	{
		free_map(cub);
		free_mlx(cub);
		exit(0);
	}
	return (0);
}
