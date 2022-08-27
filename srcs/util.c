/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:05:33 by ejang             #+#    #+#             */
/*   Updated: 2022/08/27 22:13:55 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

void	print_error(char *msg, t_cub *cub)
{
	free_map(cub);
	free_mlx(cub);
	printf("%s", "Error\n");
	printf("%s\n", msg);
	// system("leaks cub3d");
	exit(1);
}

void	pass_empty_line(int fd, char **line, unsigned int *map_loc)
{
	*line = get_next_line(fd);
	while (*line != NULL && (ft_strncmp(*line, "\n", ft_strlen("\n")) == 0 \
		|| is_space_line(line) == 0))
	{
		*map_loc = *map_loc + 1;
		free(*line);
		*line = get_next_line(fd);
	}
}

int	pass_empty_line_map(int fd, char **line)
{
	int	flag;

	flag = 0;
	*line = get_next_line(fd);
	while (*line != NULL && (ft_strncmp(*line, "\n", ft_strlen("\n")) == 0 \
		|| is_space_line(line) == 0))
	{
		flag = 1;
		free(*line);
		*line = get_next_line(fd);
	}
	if (*line != NULL && flag == 1)
		return (1);
	else
		return (0);
}
