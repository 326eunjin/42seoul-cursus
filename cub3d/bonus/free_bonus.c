/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:29:25 by jeyoon            #+#    #+#             */
/*   Updated: 2022/08/28 17:21:22 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../inc/cub3d_bonus.h"

void	free_map(t_cub *cub)
{
	int	i;

	if (cub->map->no != NULL)
		free(cub->map->no);
	if (cub->map->so != NULL)
		free(cub->map->so);
	if (cub->map->we != NULL)
		free(cub->map->we);
	if (cub->map->ea != NULL)
		free(cub->map->ea);
	if (cub->map->map != NULL)
	{
		i = 0;
		while (i < cub->map->map_height && cub->map->map[i] != NULL)
		{
			free(cub->map->map[i]);
			i++;
		}
	}
}

void	free_mlx(t_cub *cub)
{
	int	i;

	if (cub->mlx->buf != NULL)
	{
		i = 0;
		while (i < SCREEN_HEIGHT && cub->mlx->buf[i] != NULL)
		{
			free(cub->mlx->buf[i]);
			i++;
		}
	}
	i = 0;
	while (i < 4)
	{
		if (cub->mlx->texture[i] != NULL)
			free(cub->mlx->texture[i]);
		i++;
	}
	if (cub->mlx->win_ptr != NULL)
		mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr);
}

void	free_split(char **tmp)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (tmp[++i])
		cnt++;
	i = -1;
	while (++i < cnt)
		free(tmp[i]);
	free(tmp);
}
