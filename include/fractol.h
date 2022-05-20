/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:50 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 17:09:26 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

# define HEIGHT 800
# define WIDTH 800
# define ITER_MAX 30

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_color	color;
	int		status;
	double	julia_re;
	double	julia_im;
	double	zoom;
}	t_mlx;

int		press_esc_key(int key);
int		zoom(int key, int x, int y, t_mlx *mlx);
int		press_x_button(void);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_pixel(t_mlx *mlx);
int		set_color(int iter, t_mlx *mlx);

void	error_check(t_mlx *mlx, int argc, char **argv);
void	print_error(void);
int		check_status(t_mlx *mlx, char **argv, int argc);

long	ft_atol(char *str);
double	ft_atod(char *str);
double	cal_ret2(int i, char *str);

int		mandelbrot_set(int height_start, int width_start, int iter, t_mlx *mlx);
int		julia_set(int height_start, int width_start, int iter, t_mlx *mlx);

int		init(t_mlx *mlx);

#endif