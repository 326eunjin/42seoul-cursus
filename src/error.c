/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:50 by ejang             #+#    #+#             */
/*   Updated: 2022/05/21 18:42:09 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_check(t_mlx *mlx, int argc, char **argv)
{
	if (argc < 2 || check_status(mlx, argv, argc) == 0)
	{
		print_error();
		exit(0);
	}
	if (argc > 2 && check_status(mlx, argv, argc) == 1)
	{
		print_error();
		exit(0);
	}
	if (argc != 4 && check_status(mlx, argv, argc) == 2)
	{
		print_error();
		exit(0);
	}
}

void	print_error(void)
{
	ft_putstr_fd("INVALID PARAMETER\n", 1);
	ft_putstr_fd("MANDELBROT SET\n", 1);
	ft_putstr_fd("ex) ./fractol mandelbrot\n", 1);
	ft_putstr_fd("JULIA SET\n", 1);
	ft_putstr_fd("format : ./fractol julia float float\n", 1);
	ft_putstr_fd("ex) ./fractol julia -0.7 -0.27014", 1);
	exit(0);
}

int	check_status(t_mlx *mlx, char	**argv, int argc)
{
	mlx->zoom = 2;
	mlx->status = 0;
	mlx->julia_im = 0;
	mlx->julia_re = 0;
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
		mlx->status = 1;
	else if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
	{
		mlx->status = 2;
		if (argc == 4)
		{
			is_right(argv[2]);
			is_right(argv[3]);
			mlx->julia_re = ft_atod(argv[2]);
			mlx->julia_im = ft_atod(argv[3]);
		}
		else
		{
			mlx->julia_re = 0;
			mlx->julia_im = 0;
		}
	}
	return (mlx->status);
}
