/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:35:23 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 17:14:09 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	press_esc_key(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int	zoom(int key, int x, int y, t_mlx *mlx)
{
	if (key == 4 || key == 5)
	{
		if (key == 4)
			mlx->zoom = mlx->zoom - 0.01;
		else
			mlx->zoom = mlx->zoom + 0.01;
	}
	x = 0;
	y = 0;
	x++;
	y++;
	x = 0;
	y = 0;
	draw_pixel(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	return (0);
}

int	press_x_button(void)
{
	exit(0);
	return (0);
}
