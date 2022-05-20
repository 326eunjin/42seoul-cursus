/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:11:08 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 04:00:58 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	error_check(&mlx, argc, argv);
	if (!init(&mlx))
		return (0);
	draw_pixel(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);
	mlx_key_hook(mlx.win_ptr, press_esc_key, 0);
	mlx_hook(mlx.win_ptr, 4, 1L << 2, zoom, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
