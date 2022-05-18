/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:11:08 by ejang             #+#    #+#             */
/*   Updated: 2022/05/19 02:35:07 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// int		color_set(int iter)
// {
// 	double	r;
// 	double	g;
// 	double	b;
// 	int		color;

// 	r = sin(0.3 * (double)iter);
// 	g = sin(0.3 * (double)iter + 3) * 127 + 128;
// 	b = sin(0.3 * (double)iter + 3) * 127 + 128;
// 	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
// 	return (color);
// }

int main(int argc, char **argv)
{

    t_mlx mlx;

    if (argc < 2 || check_status(&mlx, argv) != 1 || check_status(&mlx, argv) != 2)
    {
        print_error();
        exit(0);
    }
    init(&mlx);
    if (!init(&mlx))
        return (0);
    draw_pixel(&mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);
    mlx_key_hook(mlx.win_ptr, press_esc_key, mlx.win_ptr);//esc
    //mlx_mouse_hook(mlx.win_ptr, zoom_in, mlx.win_ptr);
    //mlx_mouse_hook(mlx.mlx_ptr, zoom_out, mlx.mlx_ptr);
    mlx_loop(mlx.mlx_ptr);
}