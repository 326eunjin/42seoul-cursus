/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:50 by ejang             #+#    #+#             */
/*   Updated: 2022/05/19 02:22:30 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void print_error(void)
{
	ft_putstr_fd("INVALID PARAMETER\n",1);
	ft_putstr_fd("MANDELBROT SET\n",1);
	ft_putstr_fd("ex) ./fractol mandelbrot",1);
	ft_putstr_fd("JULIA SET\n",1);
	ft_putstr_fd("ex) ./fractol julia -0.7 -0.27014",1);
	exit(0);
}

int check_status(t_mlx *mlx, char **argv)
{
	mlx->status = 0;
	mlx->julia_im = 0;
	mlx->julia_re = 0;

	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mlx->status = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		mlx->status = 2;
		mlx->julia_re = ft_atod(argv[3]);
		mlx->julia_im = ft_atod(argv[4]);
	}
	return (0);
}

double	ft_atod(char *str)
{
	
}//ft_atol 사용!