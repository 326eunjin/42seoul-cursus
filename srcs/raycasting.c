/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:49:44 by ejang             #+#    #+#             */
/*   Updated: 2022/08/21 21:30:11 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../mlx/mlx.h"

void	cal_map(t_cub *cub)
{
	t_ray	ray;
	t_draw	draw;
	int		x;
	int		y;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		y = -1;
		while (++y < SCREEN_HEIGHT)
		{
			cub->mlx->buf[y][x] = ft_cal_color(cub->map->c);
			cub->mlx->buf[SCREEN_HEIGHT - y - 1][x] = ft_cal_color(cub->map->f);
		}
	}
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		init_ray(&ray, cub, x);
		dda(&ray, cub);
		cal_ray(&ray, cub, &draw);
		draw_line(cub, draw, x);
	}
}

void	draw(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			cub->mlx->img.data[y * SCREEN_WIDTH + x] = cub->mlx->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr, \
		cub->mlx->img.img, 0, 0);
}

int	main_loop(t_cub *cub)
{
	cal_map(cub);
	draw(cub);
	return (0);
}

void	draw_line(t_cub *cub, t_draw draw, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * TEX_HEIGHT / draw.line_height;
	tex_pos = (draw.draw_start - SCREEN_HEIGHT / 2 + \
		draw.line_height / 2) * step;
	i = draw.draw_start;
	while (i < draw.draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = cub->mlx->texture[draw.tex_num][TEX_HEIGHT * tex_y + \
			draw.tex_x];
		cub->mlx->buf[i][x] = color;
		i++;
	}
}
