/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:50 by ejang             #+#    #+#             */
/*   Updated: 2022/05/17 21:55:53 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>

typedef struct  s_img {
  void  *img;
  char  *addr;
  int   bits_per_pixel;
  int   line_length;
  int   endian;
}   t_img;

typedef struct s_mlx {
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
}   t_mlx;
