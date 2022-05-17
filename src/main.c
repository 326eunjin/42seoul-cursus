/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:11:08 by ejang             #+#    #+#             */
/*   Updated: 2022/05/17 21:40:30 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
    //bits_per_pixel이 픽셀 당 비트의 수이므로 바이트 단위로 바꾸기 위해 8로 나누면 픽셀 당 바이트를 구할 수 있습니다.
    *(unsigned int *)dst = color;
}//이를 통해 최종적으로 x,y 좌표의 픽셀의 메모리 주소를 구할 수 있음. 

int press_esc_key(int key, void *p)
{
    if (key == 53)//in linux it meas esc key
        exit(0);
    return 0;
}

int main(int argc, char **argv)
{
    t_mlx mlx;
    t_img img;
    
    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 800 , "fractol");
    img.img = mlx_new_image(mlx.mlx_ptr, 800, 800);//create image
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,  &img.line_length, &img.endian);
    //fractol making
    //to pixel
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, img.img, 0, 0);
    mlx_key_hook(mlx.win_ptr, press_esc_key, mlx.win_ptr);
    mlx_loop(mlx.mlx_ptr);
}