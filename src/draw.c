/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:34:27 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 11:19:34 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	set_color(int iter, t_mlx *mlx)
{
	mlx->color.r = 13 * (iter / 16);
	mlx->color.g = 18 * iter;
	mlx->color.b = 255 - iter / 16;
	return (mlx->color.r * 256 * 256 + mlx->color.g * 256 + mlx->color.b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_mlx *mlx)
{
	int	height_start;
	int	width_start;
	int	iter;
	int	color;

	height_start = -1;
	while (++height_start < HEIGHT)
	{
		width_start = 0;
		while (width_start < WIDTH)
		{
			iter = 0;
			if (mlx->status == 1)
				iter = mandelbrot_set(height_start, width_start, iter, mlx);
			else if (mlx->status == 2)
				iter = julia_set(height_start, width_start, iter, mlx);
			color = set_color(iter, mlx);
			if (iter == ITER_MAX)
				my_mlx_pixel_put(&mlx->img, \
				width_start, height_start, 0xDDFFFFFF);
			else
				my_mlx_pixel_put(&mlx->img, width_start, height_start, color);
			width_start++;
		}
	}
}
