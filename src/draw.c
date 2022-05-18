/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:34:27 by ejang             #+#    #+#             */
/*   Updated: 2022/05/19 02:12:56 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


void my_mlx_pixel_put(t_img *img, int x, int y, int color)//mlx_pixel_put 모방 
{
    char *dst;
    
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel/8));
    //bits_per_pixel이 픽셀 당 비트의 수이므로 바이트 단위로 바꾸기 위해 8로 나누면 픽셀 당 바이트를 구할 수 있습니다.
    *(unsigned int *)dst = color;
}//이를 통해 최종적으로 x,y 좌표의 픽셀의 메모리 주소를 구할 수 있음. 

void draw_pixel(t_mlx *mlx)
{
    int height_start = 0;
    int width_start;
    int iter;
    int color;

    while(height_start<=HEIGHT)
    {
        width_start = 0;
        while (width_start<=WIDTH)
        {
            iter = 0;
            //iter = mandelbrot_set(height_start, width_start, iter);
            iter = julia_set(height_start, width_start, iter, mlx);
            if (iter < ITER_MAX)
                printf("%d\n",iter);
            //color = color_set(iter);
            if (iter < ITER_MAX)
                my_mlx_pixel_put(&mlx->img, width_start, height_start, 0x00000000);//black
            else
               my_mlx_pixel_put(&mlx->img, width_start, height_start, 0x000000FF); //green
               //탈출 조건 2
            width_start++;
        }
        height_start++;
    }
}