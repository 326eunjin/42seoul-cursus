/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:25:47 by ejang             #+#    #+#             */
/*   Updated: 2022/08/25 22:36:52 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_cub(t_cub *cub)
{
	// check_info(cub);
	check_map(cub);
	//유효성 확인 끝
	// cub->map->f_color = ft_cal_color(cub->map->f);
	// cub->map->c_color = ft_cal_color(cub->map->c);
}
