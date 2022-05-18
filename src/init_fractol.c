/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:30:18 by ejang             #+#    #+#             */
/*   Updated: 2022/05/19 02:12:45 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
int init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH , "fractol");
    mlx->img.img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);//create image
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, mlx);
	return (1);
}