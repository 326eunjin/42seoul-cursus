/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:33:46 by ejang             #+#    #+#             */
/*   Updated: 2022/05/19 02:12:04 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int mandelbrot_set(int height_start, int width_start, int iter)
{
	double a_re;
	double b_im;
	double x;
	double x_temp;
	double y;
    
	a_re = (double)width_start/200 -2;
	b_im = (-1) *(double)height_start/200 + 2;
	x = 0;
	y = 0;
	while ((x*x + y*y <= 4)&& (iter < ITER_MAX))
	{
		x_temp = x*x - y*y + a_re;
		y = 2 * x * y + b_im;
		x = x_temp;
		iter++;
	}
	return (iter);
}

int julia_set(int height_start, int width_start, int iter, t_mlx *mlx)
{
    double a_re;
	double b_im;
	double x;
	double x_temp;
	double y;
    
    a_re = mlx->julia_re;
    b_im = mlx->julia_im;
	x = (double)width_start/200 -2;
	y = (-1) *(double)height_start/200 + 2;
    while ((x*x + y*y <= 4)&& (iter < ITER_MAX))
	{
		x_temp = x*x - y*y;
		y = 2 * x * y + b_im;
		x = x_temp + a_re;
		iter++;
	}
	return (iter);
}
