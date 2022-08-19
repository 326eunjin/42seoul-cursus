/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:48:02 by ejang             #+#    #+#             */
/*   Updated: 2022/08/19 21:28:09 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"

void	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

// void	parse_map_info(unsigned int *map_loc)
// {
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd));
// 	}
// }

void	parse_main(t_map *map, char *file_name)
{
	int				fd;
	int	map_loc;
	int				i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error("File open failed\n");
	map_loc = 0;
	//parse_map_info(fd, &map_loc);
	parse_map_size(fd, &map_loc, &(map->map_height), &(map->map_width));
	map->map = (char **)malloc(sizeof (char *) * map->map_height);
	if (map->map == NULL)
		print_error("1. Memory allocation failed");
	i = 0;
	while (i < (int)map->map_height)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->map_width);
		if (map->map[i] == NULL)
			print_error("2. Memory allocation failed");
		i++;
	}
	map_content(file_name, map, map_loc);
}
