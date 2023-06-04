/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:22:22 by ejang             #+#    #+#             */
/*   Updated: 2022/08/28 17:02:26 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/cub3d.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

void	load_image(t_cub *cub, int idx, char *path, t_img *img)
{
	int	img_width;
	int	img_height;
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, \
		path, &img_width, &img_height);
	if (img->img == NULL)
		print_error("Invalid xpm path", cub);
	img->data = (int *)mlx_get_data_addr(img->img, \
		&img->bpp, &img->size_l, &img->endian);
	while (y < img_height)
	{
		x = 0;
		while (x < img_width)
		{
			cub->mlx->texture[idx][img_width * y + x] = \
				img->data[img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->mlx->mlx_ptr, img->img);
}

void	init_struct(t_cub *cub)
{
	ft_memset(cub->info, 0, sizeof(*cub->info));
	ft_memset(cub->map, 0, sizeof(*cub->map));
	ft_memset(cub->mlx, 0, sizeof(*cub->mlx));
	cub->map->f_color = -1;
	cub->map->c_color = -1;
	cub->info->dir_x = 0;
	cub->info->dir_y = 0;
	cub->info->plane_x = 0;
	cub->info->plane_y = 0;
	cub->info->move_speed = 0.07;
	cub->info->rot_speed = 0.05;
}

void	texture_init(t_cub *cub)
{
	int		i;
	int		j;
	t_img	img;

	i = -1;
	while (++i < 4)
	{
		cub->mlx->texture[i] = (int *)malloc(sizeof(int) * \
			(TEX_HEIGHT * TEX_WIDTH));
		if (cub->mlx->texture[i] == NULL)
			print_error("Memory allocation failed", cub);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < TEX_HEIGHT * TEX_WIDTH)
			cub->mlx->texture[i][j] = 0;
	}
	load_image(cub, 0, cub->map->ea, &img);
	load_image(cub, 1, cub->map->we, &img);
	load_image(cub, 2, cub->map->no, &img);
	load_image(cub, 3, cub->map->so, &img);
}

void	buffer_init(t_cub *cub)
{
	int	i;
	int	j;

	cub->mlx->buf = (int **)malloc(sizeof(int *) * SCREEN_HEIGHT);
	if (cub->mlx->buf == NULL)
		print_error("Memory allocation failed", cub);
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		cub->mlx->buf[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH);
		if (cub->mlx->buf[i] == NULL)
			print_error("Memory allocation failed", cub);
	}
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			cub->mlx->buf[i][j] = 0;
	}
}

void	mlx_struct_init(t_cub *cub)
{
	cub->mlx->mlx_ptr = mlx_init();
	if (cub->mlx->mlx_ptr == NULL)
		print_error("MLX INIT FAILED", cub);
	cub->mlx->win_ptr = mlx_new_window(cub->mlx->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (cub->mlx->win_ptr == NULL)
		print_error("MLX INIT FAILED", cub);
	buffer_init(cub);
	texture_init(cub);
	cub->mlx->img.img = mlx_new_image(cub->mlx->mlx_ptr, \
		SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->mlx->img.data = (int *)mlx_get_data_addr(cub->mlx->img.img, \
		&cub->mlx->img.bpp, &cub->mlx->img.size_l, &cub->mlx->img.endian);
}
