/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:33:46 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 10:43:30 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot_set(int height_start, int width_start, int iter, t_mlx *mlx)
{
	double	a_re;
	double	b_im;
	double	x;
	double	x_temp;
	double	y;

	a_re = (double) width_start * ((2 * mlx->zoom) / 800) - mlx->zoom;
	b_im = (-1) * (double) height_start * ((2 * mlx->zoom) / 800) + mlx->zoom;
	x = 0;
	y = 0;
	while ((x * x + y * y <= 4) && (iter < ITER_MAX))
	{
		x_temp = x * x - y * y + a_re;
		y = 2 * x * y + b_im;
		x = x_temp;
		iter++;
	}
	return (iter);
}

int	julia_set(int height_start, int width_start, int iter, t_mlx *mlx)
{
	double	x;
	double	x_temp;
	double	y;

	x = (double) width_start * ((2 * mlx->zoom) / 800) - mlx->zoom;
	y = (-1) * (double) height_start * ((2 * mlx->zoom) / 800) + mlx->zoom;
	while ((x * x + y * y <= 4) && (iter < ITER_MAX))
	{
		x_temp = x * x - y * y;
		y = 2 * x * y + mlx->julia_im;
		x = x_temp + mlx->julia_re;
		iter++;
	}
	return (iter);
}
